// Copyright (c) 2018-2020, The uPlexa Team
// Copyright (c) 2014-2019, The Monero Project
//
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without modification, are
// permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice, this list of
//    conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice, this list
//    of conditions and the following disclaimer in the documentation and/or other
//    materials provided with the distribution.
//
// 3. Neither the name of the copyright holder nor the names of its contributors may be
//    used to endorse or promote products derived from this software without specific
//    prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
// THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
// STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
// THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Parts of this file are originally copyright (c) 2012-2013 The Cryptonote developers

#pragma once

#include <stdexcept>
#include <string>
#include <boost/uuid/uuid.hpp>


#define HARDFORK_1_HEIGHT                               1
#define CRYPTONOTE_DNS_TIMEOUT_MS                       20000

#define CRYPTONOTE_MAX_BLOCK_NUMBER                     500000000
#define CRYPTONOTE_MAX_BLOCK_SIZE                       500000000  // block header blob limit, never used!
#define CRYPTONOTE_GETBLOCKTEMPLATE_MAX_BLOCK_SIZE    	196608 //size of block (bytes) that is the maximum that miners will produce
#define CRYPTONOTE_MAX_TX_SIZE                          1000000000
#define CRYPTONOTE_PUBLIC_ADDRESS_TEXTBLOB_VER          0
#define CRYPTONOTE_MINED_MONEY_UNLOCK_WINDOW            60
#define CURRENT_TRANSACTION_VERSION                     3
#define CURRENT_BLOCK_MAJOR_VERSION                     1
#define CURRENT_BLOCK_MINOR_VERSION                     0
#define CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT              60*60*2
#define CRYPTONOTE_DEFAULT_TX_SPENDABLE_AGE             10

#define CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT_V2           60*24

#define BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW               60
#define BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW_V2            12

///////////////////////

#define CRYPTONOTE_TX_DEFAULT_MIX 10

#define STAKING_REQUIREMENT_LOCK_BLOCKS_EXCESS          20
#define STAKING_PORTIONS                                UINT64_C(0xfffffffffffffffc)
#define MAX_NUMBER_OF_CONTRIBUTORS                      4
#define MIN_PORTIONS                                    (STAKING_PORTIONS / MAX_NUMBER_OF_CONTRIBUTORS)

static_assert(STAKING_PORTIONS % MAX_NUMBER_OF_CONTRIBUTORS == 0, "Use a multiple of four, so that it divides easily by max number of contributors.");
static_assert(STAKING_PORTIONS % 2 == 0, "Use a multiple of two, so that it divides easily by two contributors.");
static_assert(STAKING_PORTIONS % 3 == 0, "Use a multiple of three, so that it divides easily by three contributors.");

#define STAKING_AUTHORIZATION_EXPIRATION_WINDOW         (60*60*24*7*2)  // 2 weeks
#define STAKING_AUTHORIZATION_EXPIRATION_AUTOSTAKE      (60*60*24*365*2) // 2 years

#define UPTIME_PROOF_BUFFER_IN_SECONDS                  (5*60) // The acceptable window of time to accept a peer's uptime proof from its reported timestamp
#define UPTIME_PROOF_FREQUENCY_IN_SECONDS               (60*60)
#define UPTIME_PROOF_MAX_TIME_IN_SECONDS		(UPTIME_PROOF_FREQUENCY_IN_SECONDS * 2 + UPTIME_PROOF_BUFFER_IN_SECONDS)


//////

// MONEY_SUPPLY - total number coins to be generated
#define MONEY_SUPPLY                                    8000000000000000000
#define EMISSION_SPEED_FACTOR_PER_MINUTE                (21)
#define FINAL_SUBSIDY_PER_MINUTE                        ((uint64_t)30)

#define CRYPTONOTE_REWARD_BLOCKS_WINDOW                 100
#define CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V2    60000 //size of block (bytes) after which reward for block calculated using block size
#define CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V1    20000 //size of block (bytes) after which reward for block calculated using block size - before first fork
#define CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V5    300000 //size of block (bytes) after which reward for block calculated using block size - second change, from v5
#define CRYPTONOTE_COINBASE_BLOB_RESERVED_SIZE          600
#define CRYPTONOTE_DISPLAY_DECIMAL_POINT                2
// COIN - number of smallest units in one coin
#define COIN                                            ((uint64_t)1000000000000) // pow(10, 12)

#define FEE_PER_KB_OLD                                  ((uint64_t)10000000000) // pow(10, 10)
#define FEE_PER_KB                                      ((uint64_t)4000000000) // Wtf?
#define FEE_PER_BYTE                                    ((uint64_t)300000)
#define DYNAMIC_FEE_PER_KB_BASE_FEE                     ((uint64_t)2000000000) // 2 * pow(10,9)
#define DYNAMIC_FEE_PER_KB_BASE_BLOCK_REWARD            ((uint64_t)10000000000000) // 10 * pow(10,12)
#define DYNAMIC_FEE_PER_KB_BASE_FEE_V5                  ((uint64_t)2000000000) // 2 * pow(10,9)
#define DYNAMIC_FEE_PER_KB_BASE_FEE_V12                 ((uint64_t)250000000) // 2.5 * pow(10,8)
#define DYNAMIC_FEE_REFERENCE_TRANSACTION_WEIGHT        ((uint64_t)240000)

#define ORPHANED_BLOCKS_MAX_COUNT                       100

#define DIFFICULTY_TARGET 			                        60 //seconds
#define DIFFICULTY_TARGET_V2                            120  // seconds
#define DIFFICULTY_TARGET_V1                            60  // seconds - before first fork
#define DIFFICULTY_WINDOW                               720 // blocks
#define DIFFICULTY_LAG                                  15  // !!!
#define DIFFICULTY_CUT                                  60  // timestamps to cut after sorting
#define DIFFICULTY_BLOCKS_COUNT                         (DIFFICULTY_WINDOW + DIFFICULTY_LAG)

#define DIFFICULTY_WINDOW_V2				120
#define DIFFICULTY_CUT_V2				6
#define DIFFICULTY_BLOCKS_COUNT_V2			(DIFFICULTY_WINDOW_V2 + 1)

#define CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_SECONDS_V1   DIFFICULTY_TARGET_V1 * CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS
#define CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_SECONDS_V2   DIFFICULTY_TARGET_V2 * CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS
#define CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS       1


#define DIFFICULTY_BLOCKS_ESTIMATE_TIMESPAN             DIFFICULTY_TARGET_V1 //just alias; used by tests


#define BLOCKS_IDS_SYNCHRONIZING_DEFAULT_COUNT          10000  //by default, blocks ids count in synchronizing
#define BLOCKS_SYNCHRONIZING_DEFAULT_COUNT_PRE_V4       200    //by default, blocks count in blocks downloading
#define BLOCKS_SYNCHRONIZING_DEFAULT_COUNT              200     //by default, blocks count in blocks downloading

#define CRYPTONOTE_MEMPOOL_TX_LIVETIME                    (86400*3) //seconds, three days
#define CRYPTONOTE_MEMPOOL_TX_FROM_ALT_BLOCK_LIVETIME     604800 //seconds, one week

#define MEMPOOL_PRUNE_DEREGISTER_LIFETIME               (2 * 60 * 60) // seconds, 2 hours

#define COMMAND_RPC_GET_BLOCKS_FAST_MAX_COUNT           1000

#define P2P_LOCAL_WHITE_PEERLIST_LIMIT                  1000
#define P2P_LOCAL_GRAY_PEERLIST_LIMIT                   5000

#define P2P_DEFAULT_CONNECTIONS_COUNT                   8
#define P2P_DEFAULT_HANDSHAKE_INTERVAL                  60           //secondes
#define P2P_DEFAULT_PACKET_MAX_SIZE                     50000000     //50000000 bytes maximum packet size
#define P2P_DEFAULT_PEERS_IN_HANDSHAKE                  250
#define P2P_DEFAULT_CONNECTION_TIMEOUT                  5000       //5 seconds
#define P2P_DEFAULT_PING_CONNECTION_TIMEOUT             2000       //2 seconds
#define P2P_DEFAULT_INVOKE_TIMEOUT                      60*2*1000  //2 minutes
#define P2P_DEFAULT_HANDSHAKE_INVOKE_TIMEOUT            5000       //5 seconds
#define P2P_DEFAULT_WHITELIST_CONNECTIONS_PERCENT       70
#define P2P_DEFAULT_ANCHOR_CONNECTIONS_COUNT            2

#define P2P_FAILED_ADDR_FORGET_SECONDS                  (60*60)     //1 hour
#define P2P_IP_BLOCKTIME                                (60*60*24)  //24 hour
#define P2P_IP_FAILS_BEFORE_BLOCK                       10
#define P2P_IDLE_CONNECTION_KILL_INTERVAL               (5*60) //5 minutes

#define P2P_SUPPORT_FLAG_FLUFFY_BLOCKS                  0x01
#define P2P_SUPPORT_FLAGS                               P2P_SUPPORT_FLAG_FLUFFY_BLOCKS

#define ALLOW_DEBUG_COMMANDS

#define CRYPTONOTE_NAME                         "mevacoin"
#define CRYPTONOTE_POOLDATA_FILENAME            "poolstate.bin"
#define CRYPTONOTE_BLOCKCHAINDATA_FILENAME      "data.mdb"
#define CRYPTONOTE_BLOCKCHAINDATA_LOCK_FILENAME "lock.mdb"
#define P2P_NET_DATA_FILENAME                   "p2pstate.bin"
#define MINER_CONFIG_FILE_NAME                  "miner_conf.json"

#define THREAD_STACK_SIZE                       5 * 1024 * 1024

#define HF_VERSION_DYNAMIC_FEE                  4
#define HF_VERSION_MIN_MIXIN_4                  6
#define HF_VERSION_MIN_MIXIN_6                  7
#define HF_VERSION_MIN_MIXIN_10                 8
#define HF_VERSION_ENFORCE_RCT                  6
#define HF_VERSION_PER_BYTE_FEE                 15 // unnecessary

#define PER_KB_FEE_QUANTIZATION_DECIMALS        8

#define HASH_OF_HASHES_STEP                     256

#define DEFAULT_TXPOOL_MAX_WEIGHT               648000000ull // 3 days at 300000, in bytes

#define BULLETPROOF_MAX_OUTPUTS                 16

// New constants are intended to go here
namespace config
{
  uint64_t const DEFAULT_FEE_ATOMIC_XMR_PER_KB = 500; // Just a placeholder!  Change me!
  uint8_t const FEE_CALCULATION_MAX_RETRIES = 10;
  uint64_t const DEFAULT_DUST_THRESHOLD = ((uint64_t)1); // 2 * pow(10, 9) -> nah. 1
  uint64_t const BASE_REWARD_CLAMP_THRESHOLD = ((uint64_t)100000000); // pow(10, 8)
  std::string const P2P_REMOTE_DEBUG_TRUSTED_PUB_KEY = "0000000000000000000000000000000000000000000000000000000000000000";

  uint64_t const CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX = 0x161f23;
  uint64_t const CRYPTONOTE_PUBLIC_INTEGRATED_ADDRESS_BASE58_PREFIX = 0x1661a3; //UPi
  uint64_t const CRYPTONOTE_PUBLIC_SUBADDRESS_BASE58_PREFIX = 294;

  uint16_t const P2P_DEFAULT_PORT = 21060;
  uint16_t const RPC_DEFAULT_PORT = 21061;
  uint16_t const ZMQ_RPC_DEFAULT_PORT = 21062;

  boost::uuids::uuid const NETWORK_ID = { {
      0xcf, 0x74, 0x21, 0x8a, 0x75, 0x61, 0x41, 0x0b, 0x8e, 0xa7, 0xa3, 0xa9, 0xc0, 0x12, 0x4b, 0x92 
    } }; // Bender's nightmare
    std::string const GENESIS_TX = "013c01ff0001d9d3b3ed826f029b2e4c0281c0b02e7c53291a94d1d0cbff8883f8024f5142ee494ffbbd08807121014351dc6ae3569a83d4a3293cffaae947b245fd788bf6dea88f95db78f9623f33";
    uint32_t const GENESIS_NONCE = 10000;

    uint64_t const GOVERNANCE_REWARD_INTERVAL_IN_BLOCKS = ((60 * 60 * 24 * 7) / DIFFICULTY_TARGET_V2);
    std::string const GOVERNANCE_WALLET_ADDRESS[] =
    {
      "UPX1YovsJSNQG886X5oZwnj5Hg9v7XVDXHYATDV5PnT4ZeFz1qcM1mo2kwT6EQeHSM7vm7fCWwYRaETeaHcpy3K81ucqjGdFna", // hardfork v7-10
      "UPX1YovsJSNQG886X5oZwnj5Hg9v7XVDXHYATDV5PnT4ZeFz1qcM1mo2kwT6EQeHSM7vm7fCWwYRaETeaHcpy3K81ucqjGdFna", // hardfork v7-10
    };

  namespace testnet
  {
    uint64_t const CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX = 0x3e5e23;
    uint64_t const CRYPTONOTE_PUBLIC_INTEGRATED_ADDRESS_BASE58_PREFIX = 0x1d0b24;
    uint64_t const CRYPTONOTE_PUBLIC_SUBADDRESS_BASE58_PREFIX = 294;

    uint16_t const P2P_DEFAULT_PORT = 22060;
    uint16_t const RPC_DEFAULT_PORT = 22061;
    uint16_t const ZMQ_RPC_DEFAULT_PORT = 22062;

    boost::uuids::uuid const NETWORK_ID = { {
        0x12 ,0xF1, 0x00, 0x61 , 0x71, 0x01 , 0x41, 0x61, 0x00, 0x31, 0x82, 0xA1, 0x12, 0x16, 0xA1, 0xA1
      } }; // Bender's daydream
    std::string const GENESIS_TX = "013c01ff000509027d0274a9939602c664d5a8b5c6831bb42c192ae57bded8c57f44b1833cb1629c1e0274e4174f847da69a48c8269a29bdd2bc473355953fc1b5860cfa3352af01043dac020213f880e3314ad9c46e9f99cc822fb23fa0d1a802a17ad0c22688b0980bba5533d0860302146144a8b7cbee8157bfea25f7f35d3cd199f4a2b6e137b3fdaade89b2a03ddac09a0c027c1a3cadd582454fcdc48f4fb68679c507604a657fa572e8c9a53ee0583b025221016f1f500ab50b6d90a3f000211387b9bb9812f166de3e29ffd999c765b5fe28e6";
    uint32_t const GENESIS_NONCE = 10001;

    uint64_t const GOVERNANCE_REWARD_INTERVAL_IN_BLOCKS = 1000;
    std::string const GOVERNANCE_WALLET_ADDRESS[] =
    {
      "UPTzc5eSdvfYQmShVDpzdT9EKRuD17YJmeC8du1bETMBLSw2wpkbExhMgdyWvvuqeNCU8sGwULnnWAzc8oB8tRiyUmPdHa6i1KZ",
      "UPTzc5eSdvfYQmShVDpzdT9EKRuD17YJmeC8du1bETMBLSw2wpkbExhMgdyWvvuqeNCU8sGwULnnWAzc8oB8tRiyUmPdHa6i1KZ",
    };
  }

  namespace stagenet
  {
    uint64_t const CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX = 0x45e23;
    uint64_t const CRYPTONOTE_PUBLIC_INTEGRATED_ADDRESS_BASE58_PREFIX = 0xe5326;
    uint64_t const CRYPTONOTE_PUBLIC_SUBADDRESS_BASE58_PREFIX = 294;

    uint16_t const P2P_DEFAULT_PORT = 23060;
    uint16_t const RPC_DEFAULT_PORT = 23061;
    uint16_t const ZMQ_RPC_DEFAULT_PORT = 23062;

    boost::uuids::uuid const NETWORK_ID = { {
        0x12 ,0xF1, 0x00, 0x61 , 0x71, 0x01 , 0x41, 0x61, 0x00, 0x31, 0x82, 0x30, 0x12, 0x16, 0xA1, 0xA1
      } }; // Bender's daydream
    std::string const GENESIS_TX = "013c01ff000509027fc3209bb760e86e5996fbbb112aa6f779c916f8a8aa6a36462ebf0c46452cf41e026af2edccde0c0a2c2b278f37449ef2c84fee1807db5d28d5ea3ead550a861dcdac0202d82dee932e8c4bd93e3fc23d08d6a3d885223f4d7a30808ac30ba29b5c2c8940d0860302dae61c5da8ac7fc3f0cc213e22717490d6204f16bf6bdd678e1285445b8ff59bc09a0c02e01ad3b8474b725b524f0b5c6ea751d0e51a8749862a843fd29251e288ef949221013768a51d237d0143cf26317779096ba2df799c0bcd0ac0c6e26493edbef7d031";
    uint32_t const GENESIS_NONCE = 10002;

    uint64_t const GOVERNANCE_REWARD_INTERVAL_IN_BLOCKS = ((60 * 60 * 24 * 7) / DIFFICULTY_TARGET_V2);
    std::string const GOVERNANCE_WALLET_ADDRESS[] =
    {
      "UPS1DiavDUqCaC1vP3m3yeLi7Pv4uBsoGgKrMj6Rka89YCGviex37t54FidnCJkEpXLmV2UoBd4zq1e5vE5yeUiG9eMJha4g3c",
      "UPS1DiavDUqCaC1vP3m3yeLi7Pv4uBsoGgKrMj6Rka89YCGviex37t54FidnCJkEpXLmV2UoBd4zq1e5vE5yeUiG9eMJha4g3c",
    };
  }
}

namespace cryptonote
{
  enum network_version // This shit isn't needed anymore.
  {
    network_version_7 = 7,
    network_version_8,
    network_version_13_utility_nodes, // Proof Of Stake w/ Utility Nodes
    network_version_10_bulletproofs, // Bulletproofs, Utility Node Grace Registration Period, Batched Governance
    network_version_11_swarms,
  };
  enum network_type : uint8_t
  {
    MAINNET = 0,
    TESTNET,
    STAGENET,
    FAKECHAIN,
    UNDEFINED = 255
  };
  struct config_t
  {
    uint64_t CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX;
    uint64_t CRYPTONOTE_PUBLIC_INTEGRATED_ADDRESS_BASE58_PREFIX;
    uint64_t CRYPTONOTE_PUBLIC_SUBADDRESS_BASE58_PREFIX;
    uint16_t P2P_DEFAULT_PORT;
    uint16_t RPC_DEFAULT_PORT;
    uint16_t ZMQ_RPC_DEFAULT_PORT;
    boost::uuids::uuid NETWORK_ID;
    std::string GENESIS_TX;
    uint32_t GENESIS_NONCE;
    uint64_t GOVERNANCE_REWARD_INTERVAL_IN_BLOCKS;
    std::string const *GOVERNANCE_WALLET_ADDRESS;
  };
  inline const config_t& get_config(network_type nettype, int hard_fork_version = 1)
  {
    static config_t mainnet = {
      ::config::CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX,
      ::config::CRYPTONOTE_PUBLIC_INTEGRATED_ADDRESS_BASE58_PREFIX,
      ::config::CRYPTONOTE_PUBLIC_SUBADDRESS_BASE58_PREFIX,
      ::config::P2P_DEFAULT_PORT,
      ::config::RPC_DEFAULT_PORT,
      ::config::ZMQ_RPC_DEFAULT_PORT,
      ::config::NETWORK_ID,
      ::config::GENESIS_TX,
      ::config::GENESIS_NONCE,
      ::config::GOVERNANCE_REWARD_INTERVAL_IN_BLOCKS,
      &::config::GOVERNANCE_WALLET_ADDRESS[0],
    };
    static config_t testnet = {
      ::config::testnet::CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX,
      ::config::testnet::CRYPTONOTE_PUBLIC_INTEGRATED_ADDRESS_BASE58_PREFIX,
      ::config::testnet::CRYPTONOTE_PUBLIC_SUBADDRESS_BASE58_PREFIX,
      ::config::testnet::P2P_DEFAULT_PORT,
      ::config::testnet::RPC_DEFAULT_PORT,
      ::config::testnet::ZMQ_RPC_DEFAULT_PORT,
      ::config::testnet::NETWORK_ID,
      ::config::testnet::GENESIS_TX,
      ::config::testnet::GENESIS_NONCE,
      ::config::testnet::GOVERNANCE_REWARD_INTERVAL_IN_BLOCKS,
      &::config::testnet::GOVERNANCE_WALLET_ADDRESS[0],
    };
    static config_t stagenet = {
      ::config::stagenet::CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX,
      ::config::stagenet::CRYPTONOTE_PUBLIC_INTEGRATED_ADDRESS_BASE58_PREFIX,
      ::config::stagenet::CRYPTONOTE_PUBLIC_SUBADDRESS_BASE58_PREFIX,
      ::config::stagenet::P2P_DEFAULT_PORT,
      ::config::stagenet::RPC_DEFAULT_PORT,
      ::config::stagenet::ZMQ_RPC_DEFAULT_PORT,
      ::config::stagenet::NETWORK_ID,
      ::config::stagenet::GENESIS_TX,
      ::config::stagenet::GENESIS_NONCE,
      ::config::stagenet::GOVERNANCE_REWARD_INTERVAL_IN_BLOCKS,
      &::config::stagenet::GOVERNANCE_WALLET_ADDRESS[0],
    };
    switch (nettype)
     {
       case MAINNET: case FAKECHAIN:
       {
         if (nettype == FAKECHAIN)
           mainnet.GOVERNANCE_REWARD_INTERVAL_IN_BLOCKS = 100;

         return mainnet;
       }

       case TESTNET:
       {
         if (hard_fork_version <= 13)
           testnet.GOVERNANCE_WALLET_ADDRESS = &::config::testnet::GOVERNANCE_WALLET_ADDRESS[0];
         else
           testnet.GOVERNANCE_WALLET_ADDRESS = &::config::testnet::GOVERNANCE_WALLET_ADDRESS[1];

         return testnet;
       }

       case STAGENET:
       {
         if (hard_fork_version <= 13)
           stagenet.GOVERNANCE_WALLET_ADDRESS = &::config::stagenet::GOVERNANCE_WALLET_ADDRESS[0];
         else
           stagenet.GOVERNANCE_WALLET_ADDRESS = &::config::stagenet::GOVERNANCE_WALLET_ADDRESS[1];

         return stagenet;
       }

       default: throw std::runtime_error("Invalid network type");
     }
   };
 }
