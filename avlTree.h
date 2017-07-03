/*
 * avlTree.h
 *
 *  Created on: 2015Äê8ÔÂ2ÈÕ
 *      Author: lh
 */

#ifndef AVLTREE_H_
#define AVLTREE_H_

typedef int datatype;
struct binNode{
    	datatype data;
    	binNode *left;
    	binNode *right;
    	binNode(const datatype & rhs,binNode *lt,binNode *rt);
    	binNode();
    };
class avlTree{
public :
	avlTree();
	avlTree(const avlTree &rhs);
	~avlTree();
	const datatype & findMax() const;
	const datatype & findMin() const;
	bool contains(const datatype &item) const;
	bool isEmpty()const;
	void printtree()const ;
	void clean();
	void insert(const datatype & item);
	void remove(const datatype & item);
	int getMaxdepth() const;

    const avlTree & operator= (const avlTree & rhs);
private:

    binNode *root;
    void insertnode(binNode * & rt,const datatype& t);
    void removenode(binNode * & rt,const datatype& t);
    void removenode_lowtree(binNode * & rt, const datatype& t);
    binNode * findMaxnode(binNode *rt)const;
    binNode * findMinnode(binNode *rt)const;
    bool cleannode(binNode *rt);
    void printTreenode(binNode *rt,int flag) const;
    binNode * clonetree(binNode *rt) const;
    bool contains(binNode *rt,const datatype& t)const;
    int getMaxdepth(binNode *rt) const;
    void printTreenode(binNode *rt) const;
};

//class


#endif /* AVLTREE_H_ */
