// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2018 The Bitcoin Core developers
// Copyright (c) 2019 The EZ25COIN Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef EZ25COIN_SCRIPT_EZ25COINCONSENSUS_H
#define EZ25COIN_SCRIPT_EZ25COINCONSENSUS_H

#include <stdint.h>

#if defined(BUILD_EZ25COIN_INTERNAL) && defined(HAVE_CONFIG_H)
#include <config/ez25coin-config.h>
  #if defined(_WIN32)
    #if defined(DLL_EXPORT)
      #if defined(HAVE_FUNC_ATTRIBUTE_DLLEXPORT)
        #define EXPORT_SYMBOL __declspec(dllexport)
      #else
        #define EXPORT_SYMBOL
      #endif
    #endif
  #elif defined(HAVE_FUNC_ATTRIBUTE_VISIBILITY)
    #define EXPORT_SYMBOL __attribute__ ((visibility ("default")))
  #endif
#elif defined(MSC_VER) && !defined(STATIC_LIBEZ25COINCONSENSUS)
  #define EXPORT_SYMBOL __declspec(dllimport)
#endif

#ifndef EXPORT_SYMBOL
  #define EXPORT_SYMBOL
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define EZ25COINCONSENSUS_API_VER 1

typedef enum ez25coinconsensus_error_t
{
    ez25coinconsensus_ERR_OK = 0,
    ez25coinconsensus_ERR_TX_INDEX,
    ez25coinconsensus_ERR_TX_SIZE_MISMATCH,
    ez25coinconsensus_ERR_TX_DESERIALIZE,
    ez25coinconsensus_ERR_AMOUNT_REQUIRED,
    ez25coinconsensus_ERR_INVALID_FLAGS,
} ez25coinconsensus_error;

/** Script verification flags */
enum
{
    ez25coinconsensus_SCRIPT_FLAGS_VERIFY_NONE                = 0,
    ez25coinconsensus_SCRIPT_FLAGS_VERIFY_P2SH                = (1U << 0), // evaluate P2SH (BIP16) subscripts
    ez25coinconsensus_SCRIPT_FLAGS_VERIFY_DERSIG              = (1U << 2), // enforce strict DER (BIP66) compliance
    ez25coinconsensus_SCRIPT_FLAGS_VERIFY_NULLDUMMY           = (1U << 4), // enforce NULLDUMMY (BIP147)
    ez25coinconsensus_SCRIPT_FLAGS_VERIFY_CHECKLOCKTIMEVERIFY = (1U << 9), // enable CHECKLOCKTIMEVERIFY (BIP65)
    ez25coinconsensus_SCRIPT_FLAGS_VERIFY_CHECKSEQUENCEVERIFY = (1U << 10), // enable CHECKSEQUENCEVERIFY (BIP112)
    ez25coinconsensus_SCRIPT_FLAGS_VERIFY_WITNESS             = (1U << 11), // enable WITNESS (BIP141)
    ez25coinconsensus_SCRIPT_FLAGS_VERIFY_ALL                 = ez25coinconsensus_SCRIPT_FLAGS_VERIFY_P2SH | ez25coinconsensus_SCRIPT_FLAGS_VERIFY_DERSIG |
                                                               ez25coinconsensus_SCRIPT_FLAGS_VERIFY_NULLDUMMY | ez25coinconsensus_SCRIPT_FLAGS_VERIFY_CHECKLOCKTIMEVERIFY |
                                                               ez25coinconsensus_SCRIPT_FLAGS_VERIFY_CHECKSEQUENCEVERIFY | ez25coinconsensus_SCRIPT_FLAGS_VERIFY_WITNESS
};

/// Returns 1 if the input nIn of the serialized transaction pointed to by
/// txTo correctly spends the scriptPubKey pointed to by scriptPubKey under
/// the additional constraints specified by flags.
/// If not nullptr, err will contain an error/success code for the operation
EXPORT_SYMBOL int ez25coinconsensus_verify_script(const unsigned char *scriptPubKey, unsigned int scriptPubKeyLen,
                                                 const unsigned char *txTo        , unsigned int txToLen,
                                                 unsigned int nIn, unsigned int flags, ez25coinconsensus_error* err);

EXPORT_SYMBOL int ez25coinconsensus_verify_script_with_amount(const unsigned char *scriptPubKey, unsigned int scriptPubKeyLen, int64_t amount,
                                    const unsigned char *txTo        , unsigned int txToLen,
                                    unsigned int nIn, unsigned int flags, ez25coinconsensus_error* err);

EXPORT_SYMBOL unsigned int ez25coinconsensus_version();

#ifdef __cplusplus
} // extern "C"
#endif

#undef EXPORT_SYMBOL

#endif // EZ25COIN_SCRIPT_EZ25COINCONSENSUS_H
