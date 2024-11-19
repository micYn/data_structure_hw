//this is the interface file of class TSet and function sort.

#ifndef TSET_H
#define TSET_H

#include <iostream>
#include <string>
using namespace std;

class TSet{
	public:
		TSet();
		TSet(string theName);
		//設定集合名稱並將所有陣列元素初始化為0
		friend const TSet operator +(const TSet& obj1,const TSet& obj2);
		//回傳兩集合之聯集集合
		friend const TSet operator *(const TSet& obj1,const TSet& obj2);
		//回傳兩集合之交集集合
		friend const TSet operator -(const TSet& obj1,const TSet& obj2);
		//回傳兩集合之差集集合
		friend bool operator >=(const TSet& obj1,const TSet& obj2);
		//判斷集合2是否包含於集合1
		friend ostream& operator <<(ostream& output,const TSet& obj);
		//輸出集合內容(名稱 、陣列內容)
		friend istream& operator >>(istream& input,TSet& obj);
		//輸入集合內容
		bool in(char ch) const;
		//this function checks whether ch is in the set(calling object).
		void getSetname() const;
		//return the calling object's setname.
	private:
		char set[256];
		//this array stores the content of the set.
		string setname;
		//this string stores the name of the set.
};

void sort(char arr[]);
//after this function, the content in arr will be sorted by ascii code and the character that is repeated will be removed.

#endif

