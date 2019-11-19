/*
字符串展开

给定一个只包含圆括号、小写字符和数字的字符串，其中的数字代表它前面的字符或者圆括号内部的子串的重复次数，允许嵌套。
比如abc2展开后为abcc，(abc)2展开后为abcabc，嵌套的形式如下：(a2(bc)2)2展开后为aabcbcaabcbc。
选用C/C++/C#/Java中的一种语言编程，对给定字符串进行展开，求展开后的长度。
注意：数字都以单个字符存在，不存在多个连续的字符表示一个整数的情况，即数字都在1至9的范围内；不存在字符串格式错误的情况。

输入
第一行是整数N, 表示下面有N行字符串，0 < N < 1000
之后N行，每行为一个字符串，字符串长度小于10000

输出
输出N行，每行对应一个展开的长度值

样例输入
3
(abc)2b2
a((a2b)2)2c
funplus2

样例输出
8
14
8
 */ 

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        string s;
        cin >> s;
        int n = s.length();
        stack<char> st;
        for(int i = 0; i < n; i ++){
            if(s[i] - '0' < 0 || s[i] - '9'> 0){
                st.push(s[i]);
            }
            else{
                if(st.top() != ')'){
                    char c = st.top();
                    for(int j = 0; j < s[i]-'1'; j ++){
                        st.push(c);
                    }             
                }
                else{
                    st.pop();
                    string tmp = "";
                    while(st.top() != '('){
                        tmp = st.top() + tmp;
                        st.pop();
                    }
                    //cout << "tmp " << tmp << endl;
                    st.pop();
                    string part = "";
                    for(int j = 0; j < s[i]-'0'; j ++){
                        part += tmp;
                    }
                    //cout << "part " << part << endl;
                    for(int k = 0; k < part.length(); k ++){
                        st.push(part[k]);
                    }
                }
            }
        }
       cout << st.size() << endl;
    }   
    return 0;
}
