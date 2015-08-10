/*
 * avlTree.cpp
 *
 *  Created on: 2015年8月2日
 *      Author: lh
 */

#include "avlTree.h"

#include <stddef.h>
#include <iostream>

using namespace std;

avlTree::avlTree() {
	root = NULL;

}
avlTree::avlTree(const avlTree &rhs) {
	root = NULL;
	if (this != &rhs) {
		this = &rhs;
	}
}
avlTree::~avlTree() {
	if (!isEmpty()) {
		clean();
	}

}
const datatype & avlTree::findMax() const {
	binNode * t = findMaxnode(root);
	if (NULL != t)
		return t->i;
	else
		throw("Empty tree!");
}

const datatype & avlTree::findMin() const {
	binNode * t = findMinnode(root);
	if (NULL != t)
		return t->i;
	else
		throw("Empty tree!");

}
bool avlTree::contains(const datatype &item) const {
	return contains(root, item);

}
bool avlTree::isEmpty() const {
	return root == NULL ? true : false;

}
void avlTree::printtree() const {
	printTreenode(root);
}
void avlTree::clean() {
	cleannode(root);
	root = NULL;
}
void avlTree::insert(const datatype & item) {
	insertnode(root, item);
}
void avlTree::remove(const datatype & item) {
	removenode(root, item);
}
const avlTree & avlTree::operator =(const avlTree & rhs) {
	if (this != &rhs) {
		clean();
		root = clonetree(rhs.root);
	}

	return *this;
}

binNode::binNode(const datatype & rhs, binNode *lt, binNode *rt) {
	this->i = rhs;
	this->left = lt;
	this->right = rt;

}

void avlTree::insertnode(binNode * & rt, const datatype& t) {
	if (NULL == rt) {
		rt = new binNode(t, NULL, NULL);

	} else {
		if (rt->i > t) {
			insertnode(rt->left, t);

		} else {
			if (rt->i < t) {
				insertnode(rt->right, t);
			}
		}

	}

}
void avlTree::removenode(binNode * & rt, const datatype& t) {
	if (NULL != rt) {
		if (rt->i == t) //current node
				{
			if ((NULL == rt->left) && (NULL == rt->right)) //no child
					{
				binNode * oldnode = rt;
				rt = NULL;
				delete oldnode;

			} else {
				if ((NULL != rt->left) && (NULL != rt->right)) //2 child
						{ //指向左子树，找到左子树的最右节点，右节点的右儿子指向右节点
					binNode * oldnode = rt;
					binNode * oldleft = rt->left;
					binNode * oldright = rt->right;
					//record current;
					rt = rt->left;
					binNode * tmp = findMaxnode(oldleft);
					tmp->right = oldright;

					delete oldnode;
				} else //1 child
				{
					binNode * oldnode = rt;
					rt = (rt->left != NULL ? rt->left : rt->right);
					delete oldnode;

				}

			}
		} else {
			if (rt->i < t) {
				removenode(rt->left, t);
			} else {
				removenode(rt->right, t);
			}
		}
	}

}
binNode * avlTree::findMaxnode(binNode *rt) const {
	if (NULL != rt) {
		if (NULL == rt->right) {
			return (rt);
		} else {
			return (findMinnode(rt->right));
		}

	} else {
		return NULL;
	}

}
binNode * avlTree::findMinnode(binNode *rt) const {
	if (NULL != rt) {
		if (NULL == rt->left) {
			return (rt);
		} else {
			return (findMinnode(rt->left));
		}

	} else {
		return NULL;
	}

}
bool avlTree::cleannode(binNode *rt) {
	if (NULL == rt) {
		return false;
	} else {
		if ((NULL == rt->left) && (NULL == rt->right)) {
			delete rt;
		} else {
			if (NULL != rt->left) {
				cleannode(rt->left);
				//rt->left=NULL;

			}
			if (NULL != rt->left) {
				cleannode(rt->right);
				//rt->right=NULL;
			}

		}
		rt = NULL;

	}
	return true;

}
void avlTree::printTreenode(binNode *rt) const {
	if (NULL == rt) {
		cout << "NULLEND" << endl;

	} else {
		cout << "NodeValue:" << rt->i << endl;
		cout << "NodeLeftChild:" << endl;
		printTreenode(rt->left);
		cout << "NodeRightChild:" << endl;
		printTreenode(rt->right);
	}

}
binNode * avlTree::clonetree(binNode *rt) const {
	binNode *ret = NULL;
	if (rt != NULL) {
		ret = new binNode(rt->i, clonetree(rt->left), clonetree(rt->right));
	}
	return ret;
}
bool avlTree::contains(binNode *rt, const datatype& t) const {
	if (NULL != rt) {
		if (rt->i == t) {
			return true;
		}
		if (rt->i > t) {
			return contains(rt->left, t);

		} else // (rt->i<t)
		{
			return contains(rt->right, t);
		}

	}
	return false;

}

