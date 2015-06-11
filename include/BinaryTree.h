//
//  BinaryTree.h
//  Reconstructor
//
//  Created by Luwei Yang on 6/10/15.
//  Copyright (c) 2015 Luwei Yang. All rights reserved.
//

#ifndef Reconstructor_BinaryTree_h
#define Reconstructor_BinaryTree_h

class BinaryNode;

class BinaryTree {
    
    // the ptr to the root node
    BinaryNode *root_;
    
    // the depth of the tree
    int depth_;
    
public:
    
    // Deallocate the octree, include the root node
    void deallocate();
    
    // return the ptr of root node
    BinaryNode* rootNode();
    
    // Count the cells, from root to its childrens
    long long nodeCounts();
    
    // Iterator, pre-order iterate the nodes
    class NodeIterator
    {
    public:
        // Default iterator with NULL ptr
        NodeIterator();
        
        // Default iterator
        NodeIterator(OctreeCell *cell);
        
        // Reload '++' operator for iterating next cell
        NodeIterator& operator ++ (int);
        
        // Get the cell ptr
        inline BinaryNode* operator *()
        {
            return currentNode;
        }
        
        // Treat the iterator as OctreeCell ptr
        inline BinaryNode* operator ->()
        {
            return currentNode;
        }
        
        inline bool operator == (const BinaryNode & rhs) const
        {
            return ((currentNode != nullptr)? this->currentNode != rhs.currentNode: rhs.currentNode == nullptr);
        }
        
        inline bool operator != (const BinaryNode & rhs) const
        {
            // Currently we compare the ptr address
            return ((currentNode != nullptr)? this->currentNode != rhs.currentNode: rhs.currentNode != nullptr);
        }
        
    private:
        std::queue<BinaryNode*> iteration_queue;
        BinaryNode* currentNode;
    };
};


#endif
