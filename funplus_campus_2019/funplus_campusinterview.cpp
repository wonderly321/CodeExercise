/*
�ַ���չ��

����һ��ֻ����Բ���š�Сд�ַ������ֵ��ַ��������е����ִ�����ǰ����ַ�����Բ�����ڲ����Ӵ����ظ�����������Ƕ�ס�
����abc2չ����Ϊabcc��(abc)2չ����Ϊabcabc��Ƕ�׵���ʽ���£�(a2(bc)2)2չ����Ϊaabcbcaabcbc��
ѡ��C/C++/C#/Java�е�һ�����Ա�̣��Ը����ַ�������չ������չ����ĳ��ȡ�
ע�⣺���ֶ��Ե����ַ����ڣ������ڶ���������ַ���ʾһ������������������ֶ���1��9�ķ�Χ�ڣ��������ַ�����ʽ����������

����
��һ��������N, ��ʾ������N���ַ�����0 < N < 1000
֮��N�У�ÿ��Ϊһ���ַ������ַ�������С��10000

���
���N�У�ÿ�ж�Ӧһ��չ���ĳ���ֵ

��������
3
(abc)2b2
a((a2b)2)2c
funplus2

�������
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
