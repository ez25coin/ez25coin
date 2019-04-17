// Copyright (c) 2011-2014 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef EZ25COIN_QT_EZ25COINADDRESSVALIDATOR_H
#define EZ25COIN_QT_EZ25COINADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class EZ25COINAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit EZ25COINAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

/** EZ25COIN address widget validator, checks for a valid ez25coin address.
 */
class EZ25COINAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit EZ25COINAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

#endif // EZ25COIN_QT_EZ25COINADDRESSVALIDATOR_H
