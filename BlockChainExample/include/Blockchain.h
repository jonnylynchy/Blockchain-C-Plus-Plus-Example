//
//  Blockchain.h
//  BlockChainExample
//
//  Created by Jon on 1/10/18.
//  Copyright © 2018 Crypto Enthusiasts. All rights reserved.
//

#ifndef Blockchain_h
#define Blockchain_h

#include <vector>

// Blockchain Class
class Blockchain
{
private:
    Block createGenesisBlock();
    std::vector<Block> chain;

public:
    // Constuctor
    Blockchain();
    
    // Public Functions
    std::vector<Block> getChain();
    Block *getLatestBlock();
    bool isChainValid();
    void addBlock(TransactionData data);
    void printChain();
};

#endif /* Blockchain_h */
