/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 9, 2013
 Update:     Jul 19, 2013 (Refactor)
 Problem:    Implement strStr()
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_28
 Notes:
 Implement strStr().
 Returns a pointer to the first occurrence of needle in haystack, or null if needle is not part of haystack.

 Solution: Check in the haystack one by one. If not equal to needle, reset the pointer.
 */

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        while(true)
        {
            char *h = haystack, *n = needle;
            while (*n != '\0' && *h == *n)
            {
                h++; 
                n++;
            }
            if (*n == '\0') return haystack;
            if (*h == '\0') return NULL;
            haystack++;
        }
    }
};

/*
 Author:     wenyuanhust, wenyuanhust@gmail.com
 Date:       Nov 6, 2014
 Update:     Nov 6, 2014 (Refactor)
 Problem:    Implement strStr()
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_28
 Notes:
Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Update (2014-11-02):
The signature of the function had been updated to return the index instead of the pointer. 
If you still see your function signature returns a char * or String,
please click the reload button  to reset your code definition.
 */
class Solution {
public:
    int strStr(char *haystack, char *needle) {
        if(!*needle) return 0;
        if(haystack == nullptr || needle == nullptr || !*needle) return -1;
        
        int fh = 0, fn = 0;
        char *ph_back = haystack; 
        for(char *pn = needle; *pn; pn++, ph_back++){
            if(!*ph_back) return -1;
            else fh += *ph_back;            
            fn += *pn;
        }
        ph_back--;
        
        for(char *ph = haystack; *ph_back; ){
            if(fn == fh){
                char *pn_tmp = needle, *ph_tmp = ph;
                for(; *pn_tmp; pn_tmp++, ph_tmp++){
                    if(*ph_tmp != *pn_tmp)
                        break;
                }
                if(!*pn_tmp) return ph - haystack;
            }

            fh -= *ph;
            ph++;
            ph_back++;
            fh += *ph_back;    
        }
        return -1;
    }
};
