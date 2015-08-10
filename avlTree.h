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
    	datatype i;
    	binNode *left;
    	binNode *right;
    	binNode(const datatype & rhs,binNode *lt,binNode *rt);
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
    const avlTree & operator= (const avlTree & rhs);
private:

    binNode *root;
    void insertnode(binNode * & rt,const datatype& t);
    void removenode(binNode * & rt,const datatype& t);
    binNode * findMaxnode(binNode *rt)const;
    binNode * findMinnode(binNode *rt)const;
    bool cleannode(binNode *rt);
    void printTreenode(binNode *rt) const;
    binNode * clonetree(binNode *rt) const;
    bool contains(binNode *rt,const datatype& t)const;
};

//class


#endif /* AVLTREE_H_ */
