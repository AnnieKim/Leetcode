class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        char *p, *q;
        while(p = haystack++){
            q = needle;
            while(*p != '\0' && *q != '\0' && *p == *q){
                p++;
                q++;
            }
            if(*q == '\0')return haystack-1;
            if(*p == '\0')return NULL;
        }
        return NULL;
    }
};
