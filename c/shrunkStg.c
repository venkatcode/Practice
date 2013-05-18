/*
 *
 *   Author: Venkat Viswanathan
 *   This program takes string of any length which is made of characters 'a', 'b', 'c'. It will replace pattern as per the rules
 *   "ab" -> "c"
 *   "ba" -> "c"
 *   "bc" -> "a"
 *   "cb" -> "a"
 *   "ca" -> "b"
 *   "ac" -> "b"
 *   Further it will do it recusively for shrunk string. Thus 
 *   "abc"-> "cc"
 *   "abb"-> "cb"->"a"
 *   "abbab"-> "cbab"->"aab"->"ac"
 *
 *
 * /

#include <stdio.h>
#include <string.h>

#define cmpRet(stg1, stg2, sz, ret) if (!strncmp(stg1,stg2, sz)){return ret;}

char strShrink(char first, char second)
{
  size_t sz = sizeof(char) * 2;
  char stg[3];
  sprintf(stg,"%c%c", first, second);
  cmpRet(stg,"ab", sz, 'c');
  cmpRet(stg,"ac", sz, 'b');
  cmpRet(stg,"bc", sz, 'a');
  cmpRet(stg,"ba", sz, 'c');
  cmpRet(stg,"ca", sz, 'b');
  cmpRet(stg,"cb", sz, 'a');
}
 
char *shurunkStg(char *stg)
{
    char *rd=stg, *wrt=stg, *ret= stg;
    char c; 
    int idx = 1;
    if (strlen(stg) < 2)
    {
	return stg;
    } 

    while(*(rd+idx) != NULL)
    {
       if (*rd != *(rd+idx))
       {
           
           *wrt =strShrink(*rd, *(rd+idx));
           idx++;
       }
       else
       {
           wrt++;
           *wrt= *(rd+idx); rd=rd+idx; idx=1;
       }
    }
    *(wrt+1)=NULL;
    return ret;
} 
void testString( char *stg)
{
    char *testStg= malloc(strlen(stg)+1);
    sprintf(testStg, stg);
    printf("TestStg %s\n",testStg);
    printf("shrunkStg %s \n", shurunkStg(testStg));
    
}	

int main(int argc , char *argv[])
{
    
    testString("abbbbcaac");
    testString("ab");
    testString("a");
    testString("aabbcc");
    testString("aabcc");
    exit(0);
}

