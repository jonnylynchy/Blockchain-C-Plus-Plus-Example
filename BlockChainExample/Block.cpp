//
//  Block.cpp
//  BlockChainExample
//
//  Created by Jon on 1/10/18.
//  Copyright © 2018 Crypto Enthusiasts. All rights reserved.
//

#include <stdio.h>
#include <string>

#include "Block.h"
#include "TransactionData.h"

// Constructor with params
Block::Block(int idx, TransactionData d, size_t prevHash)
{
    index = idx;
    data = d;
    previousHash = prevHash;
    blockHash = generateHash();
}

// private functions
int Block::getIndex()
{
    return index;
}

/*
 Generates hash for current block
 - Includes previousHash in generation
 - ^ Very important
*/
size_t Block::generateHash()
{
    // creating string of transaction data
    std::string toHashS = std::to_string(data.amount) + data.receiverKey + data.senderKey + std::to_string(data.timestamp);
    
    // 2 hashes to combine
    std::hash<std::string> tDataHash; // hashes transaction data string
    std::hash<std::string> prevHash; // re-hashes previous hash (for combination)
    
    // combine hashes and get size_t for block hash
    return tDataHash(toHashS) ^ (prevHash(std::to_string(previousHash)) << 1);
}

// Public Functions
size_t Block::getHash()
{
    return blockHash;
}

size_t Block::getPreviousHash()
{
    return previousHash;
}

bool Block::isHashValid()
{
    return generateHash() == getHash();
}
