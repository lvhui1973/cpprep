/*
 * avlTree.cpp
 *
 *  Created on: 2015年8月2日
 *      Author: lh
 */

#include "avlTree.h"

#include <stddef.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <string>

using namespace std;

avlTree::avlTree() {
	root = NULL;

}
avlTree::avlTree(const avlTree &rhs) {
	root = NULL;
	/*if (this != &rhs) {
	 this = &rhs;
	 }*/
}
avlTree::~avlTree() {
	if (!isEmpty()) {
		clean();
	}

}
const datatype & avlTree::findMax() const {
	binNode * t = findMaxnode(root);
	if (NULL != t)
		return t->data;
	else
		throw(new string("find Max Empty tree!"));
}

const datatype & avlTree::findMin() const {
	binNode * t = findMinnode(root);
	if (NULL != t)
		return t->data;
	else
		throw(new string("find Min Empty tree!"));

}
bool avlTree::contains(const datatype &item) const {
	return contains(root, item);

}
bool avlTree::isEmpty() const {
	return root == NULL ? true : false;

}
void avlTree::printtree() const {
	cout << "++++++++++++++++Plain Display+++++++++++++++++" << endl;
	printTreenode(root, 0);
	cout << endl;
	cout << "++++++++++++++++Treeview Display+++++++++++++++++" << endl;
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
	this->data = rhs;
	this->left = lt;
	this->right = rt;

}

void avlTree::insertnode(binNode * & rt, const datatype& t) {
	if (NULL == rt) {
		rt = new binNode(t, NULL, NULL);

	} else {
		if (rt->data > t) {
			insertnode(rt->left, t);

		} else {
			if (rt->data < t) {
				insertnode(rt->right, t);
			}
		}

	}

}
void avlTree::removenode(binNode * & rt, const datatype& t) {
	if (NULL != rt) {
		if (rt->data == t) //current node
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
			if (rt->data < t) {
				removenode(rt->left, t);
			} else {
				removenode(rt->right, t);
			}
		}
	}

}
void avlTree::removenode_lowtree(binNode * & rt, const datatype& t) {
	if (NULL != rt) {
		if (rt->data == t) //current node
				{
			if ((NULL == rt->left) && (NULL == rt->right)) //no child
					{
				binNode * oldnode = rt;
				rt = NULL;
				delete oldnode;

			} else {
				if ((NULL != rt->left) && (NULL != rt->right)) //2 child
						{ //找到右子树最小的节点替换当前节点，置换为当前节点并删除右子树的最小节点

					binNode * oldright = rt->right;
					binNode * tmp = findMaxnode(oldright);
					rt->data = tmp->data;
					removenode_lowtree(oldright, rt->data);

				} else //1 child
				{
					binNode * oldnode = rt;
					rt = (rt->left != NULL ? rt->left : rt->right);
					delete oldnode;

				}

			}
		} else {
			if (rt->data < t) {
				removenode_lowtree(rt->left, t);
			} else {
				removenode_lowtree(rt->right, t);
			}
		}
	}

}
binNode * avlTree::findMaxnode(binNode *rt) const {
	if (NULL != rt) {
		if (NULL == rt->right) {
			return (rt);
		} else {
			return (findMaxnode(rt->right));
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
void avlTree::printTreenode(binNode *rt, int flag) const {
	if (NULL != rt) {
		switch (flag) {
		case 0: //mid seq
			cout << rt->data << "  ";
			printTreenode(rt->left, flag);
			printTreenode(rt->right, flag);
			break;
		case 1: //left seq
			printTreenode(rt->left, flag);
			cout << rt->data << "  ";
			printTreenode(rt->right, flag);
			break;
		case 2: //right seq
			printTreenode(rt->right, flag);
			cout << rt->data << "  ";
			printTreenode(rt->left, flag);
			break;
		}

	}

}
void avlTree::printTreenode(binNode *rt) const { //TODO
	if (NULL != rt) {
		int d = getMaxdepth(rt);
		//count total tree length
		int n = 0;

		for (int i = 0; i < d; i++) {
			n += pow(2, i);
		}
		cout << "d=" << d << " n=" << n << endl;

		vector<binNode *> b;

		binNode *tmp = new binNode(rt->data, rt->left, rt->right);
		b.push_back(tmp);

		int pstart = 0;

		for (int i = 0; i < d - 1; i++) { //count start & upper element

			int plinen = pow(2, i);
			//cout<<"pstart="<<pstart<<" nstart="<<nstart<<" plinen="<<plinen<<endl;
			for (int j = 0; j < plinen; j++) {
				//cout<<"i="<<i<<" j="<<j<<" pstart+j="<<pstart+j<<endl;
				if (NULL == b[pstart + j]) {
					b.push_back(NULL);
					b.push_back(NULL);
				} else {
					if (b[pstart + j]->left != NULL) {

						binNode *t = new binNode(b[pstart + j]->left->data,
								b[pstart + j]->left->left,
								b[pstart + j]->left->right);
						b.push_back(t);
					} else {
						b.push_back(NULL);
					}
					if (NULL != b[pstart + j]->right) {
						binNode *t = new binNode(b[pstart + j]->right->data,
								b[pstart + j]->right->left,
								b[pstart + j]->right->right);
						b.push_back(t);
					} else {
						b.push_back(NULL);
					}
				}
			}
			pstart += pow(2, i);
		}
		//print all in test
		cout << "b.size()=" << b.size() << endl;
		if (b.size() > 0) {
			pstart = 0;

			for (int i = 0; i < d; i++) { //count start & upper element
				int plinen = pow(2, i);
				for (int j = 0; j < plinen; j++) {
					//cout<<"pstart="<<pstart<< " plinen="<<plinen<<" pstart+j="<<pstart+j<<endl;
					if (NULL != b[pstart + j]) {
						cout << b[pstart + j]->data << " ";
					} else {
						cout << "XXX ";
					}
				}

				pstart = pstart + pow(2, i);

				cout << endl;
			}
		}
		for (unsigned int i = 0; i < b.size(); i++) {
			if (NULL != b[i]) {
				delete b[i];
				//b.erase(i);
			}
		}

	}
}

binNode * avlTree::clonetree(binNode *rt) const {
	binNode *ret = NULL;
	if (rt != NULL) {
		ret = new binNode(rt->data, clonetree(rt->left), clonetree(rt->right));
	}
	return ret;
}
bool avlTree::contains(binNode *rt, const datatype& t) const {
	if (NULL != rt) {
		if (rt->data == t) {
			return true;
		}
		if (rt->data > t) {
			return contains(rt->left, t);

		} else // (rt->i<t)
		{
			return contains(rt->right, t);
		}

	}
	return false;

}
int avlTree::getMaxdepth(binNode *rt) const {
	if (NULL == rt) {
		return 0;
	}
	int l = getMaxdepth(rt->left);
	int r = getMaxdepth(rt->right);
	return l > r ? l + 1 : r + 1;

}
int avlTree::getMaxdepth() const {
	return getMaxdepth(root);
}

