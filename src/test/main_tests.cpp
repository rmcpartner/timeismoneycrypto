// Copyright (c) 2014 The Bitcoin Core developers
// Copyright (c) 2014-2015 The Dash developers
// Copyright (c) 2015-2017 The PIVX developers 
// Copyright (c) 2015-2017 The ALQO developers
// Copyright (c) 2017-2018 The TimeIsMoney developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "primitives/transaction.h"
#include "main.h"

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(main_tests)

CAmount nMoneySupplyPoWEnd = 41769651 * COIN;

BOOST_AUTO_TEST_CASE(subsidy_limit_test)
{
    CAmount nSum = 0;
    for (int nHeight = 0; nHeight < 1; nHeight += 1) {
        /* premine in block 1 */
        CAmount nSubsidy = GetBlockValue(nHeight);
        BOOST_CHECK(nSubsidy <= 5000000 * COIN);
        nSum += nSubsidy;
    }
    for (int nHeight = 1; nHeight < 75000; nHeight += 1) {
        CAmount nSubsidy = GetBlockValue(nHeight);
        BOOST_CHECK(nSubsidy <= 10 * COIN);
        nSum += nSubsidy;
    }
    for (int nHeight = 75000; nHeight < 150000; nHeight += 1) {
        CAmount nSubsidy = GetBlockValue(nHeight);
        BOOST_CHECK(nSubsidy <= 10.75 * COIN);
        nSum += nSubsidy;
    }
    for (int nHeight = 150000; nHeight < 225000; nHeight += 1) {
        CAmount nSubsidy = GetBlockValue(nHeight);
        BOOST_CHECK(nSubsidy <= 11.5 * COIN);
        nSum += nSubsidy;
    }
	for (int nHeight = 225000; nHeight < 300000; nHeight += 1) {
        CAmount nSubsidy = GetBlockValue(nHeight);
        BOOST_CHECK(nSubsidy <= 12.25 * COIN);
        nSum += nSubsidy;
    }
	for (int nHeight = 300000; nHeight < 375000; nHeight += 1) {
        CAmount nSubsidy = GetBlockValue(nHeight);
        BOOST_CHECK(nSubsidy <= 13 * COIN);
        nSum += nSubsidy;
    }
	for (int nHeight = 375000; nHeight < 450000; nHeight += 1) {
        CAmount nSubsidy = GetBlockValue(nHeight);
        BOOST_CHECK(nSubsidy <= 13.75 * COIN);
        nSum += nSubsidy;
    }
	for (int nHeight = 450000; nHeight < 525000; nHeight += 1) {
        CAmount nSubsidy = GetBlockValue(nHeight);
        BOOST_CHECK(nSubsidy <= 14.5 * COIN);
        nSum += nSubsidy;
    }
	for (int nHeight = 525000; nHeight < 600000; nHeight += 1) {
        CAmount nSubsidy = GetBlockValue(nHeight);
        BOOST_CHECK(nSubsidy <= 15.25 * COIN);
        nSum += nSubsidy;
    }
    for (int nHeight = 600000; nHeight < 675000; nHeight += 1) {
        CAmount nSubsidy = GetBlockValue(nHeight);
        BOOST_CHECK(nSubsidy <= 16 * COIN);
        nSum += nSubsidy;
    }
	
	BOOST_CHECK(nSum > 0 && nSum <= nMoneySupplyPoWEnd);
}

BOOST_AUTO_TEST_SUITE_END()
