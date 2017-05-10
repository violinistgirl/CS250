/* Modify this file! */

#ifndef _BINARY_SEARCH_TREE_HPP
#define _BINARY_SEARCH_TREE_HPP

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

template <typename TK, typename TD>
//! A template node class, to be used in the BinarySearchTree class.
class Node      // done
{
public:
    //! Initializes left and right pointers to nullptr.
    Node()
    {
        ptrLeft = nullptr;
        ptrRight = nullptr;
    }

    //! Destroys left and right children, if they are not pointing to nullptr.
    ~Node()
    {
        // destroy children
        if ( ptrLeft != nullptr ) { delete ptrLeft; }
        if ( ptrRight != nullptr ) { delete ptrRight; }
    }

    //! Pointer to the left child of the node, which is lesser in value
    Node<TK, TD>* ptrLeft;

    //! Pointer to the right chlid of the node, which is greater in value
    Node<TK, TD>* ptrRight;

    //! The data stored by the node
    TD data;

    //! The key of this node
    TK key;
};

template <typename TK, typename TD>
//! A template binary search tree class
class BinarySearchTree
{
public:
    //! Initializes the node count to 0, and the root pointer to nullptr.
    BinarySearchTree()	// done
    {
        m_ptrRoot = nullptr;
        m_nodeCount = 0;
    }

    //! Destroys the root node
    ~BinarySearchTree()		// done
    {
        if ( m_ptrRoot != nullptr ) { delete m_ptrRoot; }
    }

    //! Creates a new node for the tree and assigns the data of that node to the parameter passed in.
    /**
        If the tree is empty, the new data goes at the root node.
        Otherwise, we will have to recurse through the tree in order to
        find the correct position for our new data.

        @param newKey const TK&, the key to index this new item under
        @param newData const TD&, the new data to be added to the tree
        @return <void>
    */
    void Insert( const TK& newKey, const TD& newData ) /////////////////////////////////
    {
		Node<TK, TD>* newNode = new Node<TK, TD>;
		newNode->key = newKey;
		newNode->data = newData;

		if (m_nodeCount == 0) {
			m_ptrRoot = newNode;
		}
		else {
			Node<TK, TD>* ptrCurrent = m_ptrRoot;
			Node<TK, TD>* ptrParent = new Node<TK, TD>;

			while (ptrCurrent != nullptr) {
				ptrParent = ptrCurrent;
				if (newKey < ptrCurrent->key) {
					ptrCurrent = ptrCurrent->ptrLeft;
					if (ptrCurrent == nullptr) {
						ptrParent->ptrLeft = newNode;
					}
				}
				else {
					ptrCurrent = ptrCurrent->ptrRight;

					if (ptrCurrent == nullptr) {
						ptrParent->ptrRight = newNode;
					}
				}				
			}	
		}

		m_nodeCount++;
    }

    //! Deletes the Node that contains the given data, if it exists in the tree.
    /**
        Search the tree for a Node that contains the data. This Node will be removed.

        You must handle children of the node based on how many it has.

        See the Sherrod attachment for the detailed code, page 310 - 312.

        @param data const TK&, the data to be removed from the tree.
        @return <void>
    */
    void Delete( const TK& key )
    {
		if (m_ptrRoot != nullptr) {
			Node<TK, TD>* thisNode = FindNode(key);
			Node<TK, TD>* parentNode = nullptr;
			bool isLeft = true;
			if (thisNode != nullptr) {
				if (thisNode != m_ptrRoot) {
					parentNode = FindParentOfNode(key);
					if (parentNode->ptrRight->key == key) {
						isLeft = false;
					}

					if (thisNode->ptrLeft == nullptr && thisNode->ptrRight == nullptr) {
						if (isLeft) {
							parentNode->ptrLeft = nullptr;
						}
						else {
							parentNode->ptrRight = nullptr;
						}
					}
					else if (thisNode->ptrLeft == nullptr) {
						if (isLeft) {
							parentNode->ptrLeft = thisNode->ptrRight;
						}
						else {
							parentNode->ptrRight = thisNode->ptrRight;
						}
					}
					else if (thisNode->ptrRight == nullptr) {
						if (isLeft) {
							parentNode->ptrLeft = thisNode->ptrLeft;
						}
						else {
							parentNode->ptrRight = thisNode->ptrLeft;
						}
					}
				}
				else {
					if (thisNode->ptrLeft == nullptr && thisNode->ptrRight == nullptr) {
						m_ptrRoot = nullptr;
					}
					else if (thisNode->ptrLeft == nullptr) {
						m_ptrRoot = thisNode->ptrRight;
					}
					else if (thisNode->ptrRight == nullptr) {
						m_ptrRoot = thisNode->ptrLeft;
					}
				}

				if (thisNode->ptrLeft != nullptr && thisNode->ptrRight != nullptr) {
					Node<TK, TD>* temp = thisNode->ptrRight;
					Node<TK, TD>* successor = thisNode;
					Node<TK, TD>* successorParent = thisNode;

					while (temp != nullptr) {
						successorParent = successor;
						successor = temp;
						temp = temp->ptrLeft;
					}

					if (successor != thisNode->ptrRight) {
						successorParent->ptrLeft = successor->ptrRight;
						successor->ptrRight = thisNode->ptrRight;
					}

					if (parentNode == nullptr) {
						m_ptrRoot = successor;
					}
					else if(isLeft){
						thisNode = parentNode->ptrLeft;
						parentNode->ptrLeft = successor;
					}
					else {
						thisNode = parentNode->ptrRight;
						parentNode->ptrRight = successor;
					}

					successor->ptrLeft = thisNode->ptrLeft;
				}

				thisNode->ptrLeft = nullptr;
				thisNode->ptrRight = nullptr;
				delete thisNode;
				m_nodeCount--;
			}
		}
    }
	

    //! Searches the tree for the key provided and returns true if found, false if not.
    /**
        @return <bool> whether or not the key is found in the tree.
    */
    bool Contains( const TK& key )
    {		
		Node<TK, TD>* thisNode = nullptr;
			thisNode = FindNode(key);
		if (thisNode == nullptr) {
			return false;
		}

		return true;
    }

    //! Displays the keys of the nodes in the tree, in in-order format.
    /**
        This function creates a stringstream and calls the recursive
        GetInOrder function. It will return the keys of the nodes in the tree
        in string format.

        @return <string> The keys of the nodes in the tree, in in-order format, as a string.
    */
    string GetInOrder()     // done
    {
        stringstream stream;
        GetInOrder( m_ptrRoot, stream );
        return stream.str();
    }

    //! Displays the keys of the nodes in the tree, in pre-order format.
    /**
        This function creates a stringstream and calls the recursive
        GetPreOrder function. It will return the keys of the nodes in the tree
        in string format.

        @return <string> The keys of the nodes in the tree, in pre-order format, as a string.
    */
    string GetPreOrder()     // done
    {
        stringstream stream;
        GetPreOrder( m_ptrRoot, stream );
        return stream.str();
    }

    //! Displays the keys of the nodes in the tree, in post-order format.
    /**
        This function creates a stringstream and calls the recursive
        GetPostOrder function. It will return the keys of the nodes in the tree
        in string format.

        @return <string> The keys of the nodes in the tree, in post-order format, as a string.
    */
    string GetPostOrder()     // done
    {
        stringstream stream;
        GetPostOrder( m_ptrRoot, stream );
        return stream.str();
    }

    //! Returns the largest value in the tree
    /**
        Keep in mind that, for any given node, anything to
        the RIGHT is greater than that node.

        @return <TK*> Largest key in the tree, or nullptr if tree is empty
    */
    TK* GetMax()     // done
    {
        return GetMax( m_ptrRoot );
    }

    //! Returns the amount of nodes in the tree.
    /**
        @return <int> the amount of nodes in the tree
    */
    int GetCount()     // done
    {
        return m_nodeCount;
    }

    //! Returns the height of the entire tree; must be max height.
    /**
        @return <int> height of the tree
    */
    int GetHeight()     // done
    {
        if ( m_ptrRoot == nullptr )
        {
            return 0;
        }

        return GetHeight( m_ptrRoot );
    }

    //! Returns the data based on a key passed in, or nullptr if not present.
    /**
        Search the binary tree for the node that has the given key
        (can use the FindNode function), and returns the data associated
        with that node. If no node is found, return nullptr instead.

        @param key <TK&>    the key of the node we're searching for
        @return <TD*>       data of the node that has the key given
    */
    TD* GetData( const TK& key )	// done
    {
        Node<TK, TD>* node = FindNode( key );

        if ( node == nullptr )
        {
            return nullptr;
        }

        return &(node->data);
    }

private:
    //! Returns the Node* that contains the key, or nullptr if data is not in the tree.
    /**
        Similar to the Contains function, you will have to traverse the tree to find
        the key. If you find the Node that contains this data, you will return
        the Node*.

        @param data <const TK&>, the key that we are searching for.
        @return <Node<T>*> the Node* that contains the key. Otherwise, nullptr if data is not found.
    */
    Node<TK, TD>* FindNode( const TK& key )
    {
		Node<TK, TD>* ptrCurrent = m_ptrRoot;

		while (ptrCurrent->key != key) {			
			if (key < ptrCurrent->key) {
				ptrCurrent = ptrCurrent->ptrLeft;
			}
			else {
				ptrCurrent = ptrCurrent->ptrRight;
			}
			if (ptrCurrent == nullptr) { return nullptr; }
		}
		return ptrCurrent;
		
    }

    //! Returns the PARENT Node* of the Node* that contains the key, or nullptr if data is not in the tree.
    /**
        Similar to the FindNode function, you will instead return the PARENT NODE
        of the node that contains the key, rather than the node itself.

        @param data <const TK&>,    the key we are searching for; but going to return the parent of this node.
        @return <Node<TK, TD>*>     the Node* that contains the data. Otherwise, nullptr if key is not found.
    */
    Node<TK, TD>* FindParentOfNode( const TK& key )
    {
		Node<TK, TD>* ptrParent = nullptr;
		Node<TK, TD>* ptrCurrent = m_ptrRoot;		

			while (ptrCurrent->key != key) {
				ptrParent = ptrCurrent;
				if (key < ptrCurrent->key) {
					ptrCurrent = ptrCurrent->ptrLeft;
				}
				else {
					ptrCurrent = ptrCurrent->ptrRight;
				}
				if (ptrCurrent == nullptr) { return nullptr; }
			}
			return ptrParent;
    }

    // RECURSIVE FUNCTIONS: These will recurse through
    // the tree to do the specified operation and
    // return the result back to the interface function,
    // to return back to the caller.

    //! Recurses through the tree and finds the proper location for the new data.
    /**
        TERMINATING CASE: If ptrCurrent is a nullptr, then we have traversed
        to a space that is available for our new node. Create our new node here
        and set up the data.

        RECURSIVE CASE: If ptrCurrent is already taken, we must figure out whether
        to recurse LEFT or RIGHT, based on the value of newData compared to the
        prtCurrent's data.

        @param newKey const TK&,            the key to index this new item under
        @param newData const TD&,           the new data to be added to the tree
        @param ptrCurrent Node<TK, TD>*,    the pointer to the current root of a subtree;
            will traverse left or right if newKey is less-than or greater-than, respectively.
        @return <void>
    */
    void RecursiveInsert( const TK& newKey, const TD& newData, Node<TK, TD>* ptrCurrent )
    {
		if (ptrCurrent = nullptr) {
			Node<TK, TD>* newNode = new Node<TK, TD>*;
			newNode->key = newKey;
			newNode->data = newData;
			ptrCurrent = newNode;
		}
		else {
			if (ptrCurrent->data < newData) {
				RecursiveInsert(newKey, newData, ptrCurrent->ptrLeft);
			}
			else if (ptrCurrent->data > newData) {
				RecursiveInsert(newKey, newData, ptrCurrent->ptrRight);
			}
		}
    }

    //! Recurses through the tree in IN-ORDER order, writing to the stream.
    /**
        In order will display the items in the tree in ascending order.
        From an algorithmic point of view, for whatever node it is on, it will:
            - Display the left node item
            - Display the current node item
            - Display the right node item
        
        To write out to the stream, simply use:
        stream << ptrCurrent->key << " ";

        Note that it is expected that you will have a leading space " "
        at the end of the generated string.
    */
    void GetInOrder( Node<TK, TD>* ptrCurrent, stringstream& stream )
    {
		if (ptrCurrent == nullptr) {
			return;
		}
		else {
			GetInOrder(ptrCurrent->ptrLeft, stream);
			stream << ptrCurrent->key << " ";
			GetInOrder(ptrCurrent->ptrRight, stream);

		}
    }

    //! Recurses through the tree in PRE-ORDER order, writing to the stream.
    /**
        In order will display the items in the tree pre-order.
        From an algorithmic point of view, for whatever node it is on, it will:
            - Display the current node item
            - Display the left node item
            - Display the right node item

        Note that it is expected that you will have a leading space " "
        at the end of the generated string.
    */
    void GetPreOrder( Node<TK, TD>* ptrCurrent, stringstream& stream )
    {
		if (ptrCurrent == nullptr) {
			return;
		}
		else {
			stream << ptrCurrent->key << " ";
			GetPreOrder(ptrCurrent->ptrLeft, stream);
			GetPreOrder(ptrCurrent->ptrRight, stream);
		}
    }

    //! Recurses through the tree in POST-ORDER order, writing to the stream.
    /**
        In order will display the items in the tree post-order.
        From an algorithmic point of view, for whatever node it is on, it will:
            - Display the left node item
            - Display the right node item
            - Display the current node item

        Note that it is expected that you will have a leading space " "
        at the end of the generated string.
    */
    void GetPostOrder( Node<TK, TD>* ptrCurrent, stringstream& stream )
    {
		if (ptrCurrent == nullptr) {
			return;
		}
		else {
			GetPostOrder(ptrCurrent->ptrLeft, stream);
			GetPostOrder(ptrCurrent->ptrRight, stream);
			stream << ptrCurrent->key << " ";
		}
    }

    //! Recurses through the tree, going to the right-child-nodes until the max key is found.
    /**
    Items are inserted into a binary search tree in a sorted order.
    This means that larger items always get inserted to the right,
    with the maximum value being the right-most value.
    */
    TK* GetMax( Node<TK, TD>* ptrCurrent )
    {
		TK* max = nullptr;
		if (ptrCurrent->ptrRight != nullptr) {
			max = GetMax(ptrCurrent->ptrRight);
		}
		else {
			return &ptrCurrent->key;
		}
		return max;
        
    }

    /**
    Get the height of left sub tree, say leftHeight
    Get the height of right sub tree, say rightHeight
    Take the Max(leftHeight, rightHeight) and add 1 for the root and return
    Call recur­sively.
    */
    int GetHeight( Node<TK, TD>* ptrCurrent )
    {
		if (ptrCurrent != nullptr) {
			int leftHeight, rightHeight = 0;
			leftHeight = GetHeight(ptrCurrent->ptrLeft);
			rightHeight = GetHeight(ptrCurrent->ptrRight);
			if (leftHeight > rightHeight) {
				return leftHeight + 1;
			}
			else {
				return rightHeight + 1;
			}
		}
		else {
			return 0;
		}
    }

private:
    //! A pointer to the root node of the tree; TK = data type of the key, TD = data type of the data.
    Node<TK, TD>* m_ptrRoot;

    //! The amount of nodes in the tree
    int m_nodeCount;

friend class Tester;
};

#endif
