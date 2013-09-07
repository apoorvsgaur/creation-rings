#include "pa02.h"
# include <string.h>
# include <stdio.h>
# include <ctype.h>
/**
 * Count the number of characters in a null-terminated string 's' 
 * (not counting the null character).
 *
 * Example: my_strlen("foo") should yield 3.
 */
int my_strlen(const char * s) //Function to count no. of letters in a string
{   
    int count = 0; //Variable to count no. of letters in a string
    while (s[count] != '\0')
    {
      count = count + 1;
    }

    return count;
}

/**
 * Count the number of occurrences of a particular character 'c' in a
 * null-terminated string 's'.
 *
 * Example: my_countchar("foo", 'o') should yield 2.
 */
int my_countchar(const char * s, char c) //Function to count no. of a specific type of a char
{
   int count = 0; //Variable to go through each position of string
   int value = 0; //Variable to count of no. of occurances of a character
   while (s[count] != '\0')
   {
     if (s[count] == c)
     { value = value + 1;
     }
    count = count + 1;
   }

   return value;
}

/**
 * Convert an entire null-terminated string 's' to uppercase.  Only
 * alphabetical characters should be converted; numbers and symbols
 * should not be affected.  Hint: toupper(c) is a macro that yields
 * the uppercase version of a character c.
 *
 * Example: char foobar[10] = "foobar";
 * my_strupper(foobar) yields "FOOBAR".
 */
void my_strupper(char * s)//Function to convert lowercase elements to uppercase elements in a string
{  
   int count = 0;//Variable to go through each element in the string
   while (s[count] != '\0')
   { 
      if (s[count] >= 97 && s[count] <=122)//To check whether lowercase
      { 
        s[count] = s[count] - 32;//Conversion into uppercase
      }
      count = count + 1;
   }
}

/**
 * Convert an entire null-terminated string 's' to lowercase.  Only
 * alphabetical characters should be converted; numbers and symbols
 * should not be affected.  Hint: tolower(c) is a macro that yields
 * the lowercase version of a character 'c'.
 *
 * Example: char foobar[10] = "FOOBAR";
 * my_strupper(foobar) yields "foobar".
 */
void my_strlower(char * s) //Function to convert uppercase letters into lowercase letters in a string
{
  int count = 0; //Variable to go through each element in a string
   while (s[count] != '\0')
   { 
      if (s[count] >= 65 && s[count] <= 90) //To check whether uppercase
      {
        s[count] = s[count] + 32;//To convert to lowercase
      }
      count = count + 1;
   }
}

/**
 * Copy the contents of a null-terminated string 's2' into the memory
 * pointed to by 's1'.  Any existing data in 's1' will be overwritten by
 * the contents of 's2'.  Note: you can assume that there is sufficient
 * memory available in 's1'.  Hint: Don't forget to terminate the new
 * string with '\0'!
 * 
 * Example: char foo[10];
 * my_strcpy(foo, "foo") yields "foo".
 */
void my_strcpy(char * s1, const char * s2) //Function to copy one string into another
{
  strcpy (s1,s2);
}

/**
 * Copy the first 'n' characters of a null-terminated string 's2' into the
 * memory pointed to by 's1'. Any existing data in 's1' will be
 * overwritten by the contents of 's2'.  Note: you can assume that there
 * is sufficient memory available in 's1'.  Hint: Don't forget to
 * terminate the new string with '\0'!
 * 
 * Example: char foo[10];
 * my_strncpy(foo, "foo", 1) yields "f".
 */
void my_strncpy(char * s1, const char * s2, int num)//Function to copy a certain no. of elements of a string into another
{
  int i;
  for (i = 0; i < num; i++)
  {
     s1[i] = s2[i];
  }
  
  s1[i] = '\0';
    
}


/** 
 * Concatenate (append) the contents of a null-terminated string 's2'
 * onto the end of the null-terminated string 's1'.  Note: you can
 * assume that there is sufficient memory available in 's1'.  Hint:
 * Don't forget to terminate the new string with '\0'!
 * 
 * Example: char foo[10] = "foo";
 * my_strcat(foo, "bar") yields "foobar".
 */
void my_strcat(char * s1, const char * s2) //Function to concatenate one string into another
{ 
  int i = my_strlen (s1);
  int j = 0;
  for ( ;s2[j] != '\0'; i++,j++)
  {
    s1[i] = s2[j];
  }
  s1[i] = '\0';

}


/** 
 * Concatenate (append) the first n characters of a null-terminated
 * string 's2' onto the end of the null-terminated string 's1'.  Note: you
 * can assume that there is sufficient memory available in 's1'.  Hint:
 * Don't forget to terminate the new string with '\0'!
 * 
 * Example: char foo[10] = "foo";
 * my_strcat(foo, "bar", 1) yields "foob".
 */
void my_strncat(char * s1, const char * s2, int num)//Function to concatenate one string into another from a specific postion
{ 
  int i = my_strlen (s1);
  int j = 0;
  for ( ;j < num; i++,j++)
  {
    s1[i] = s2[j];
  }    
}

/**
 * Return a pointer to the first occurrence of a null-terminated
 * substring 's2' in a null-terminated string 's1'.  If 's2' does not appear
 * in 's1', the empty (NULL) pointer is returned.
 * 
 * Example: my_strstr("hello world!", "test") will yield 0 (NULL).
 * Example(2): my_strstr("foobar", "bar") will yield a pointer to the
 * "bar" portion of the "foobar" argument.
 */

const char *my_strstr(const char * s1, const char * s2) //Function to point a specific occurance of a string from another
{ char *a;
  a = strstr (s1,s2); 

  if (*a != -1)//If the string wasnt found
  return a;

  else
  return NULL;

}



/**
 * Insert a null-terminated string s2 in the null-terminated string s1
 * at position pos.  All characters following position pos in s1 will
 * be moved to follow directly after the inserted characters from s2;
 * no characters will be overwritten.  Note: you can assume that there
 * is sufficient memory available in s1.
 * 
 * Hint: there is no need to create any temporary memory; simply copy
 * the contents of the string after position pos to its new location
 * starting from the back of the string and going forwards.
 * 
 * Insertions should happen BEFORE the character position referenced
 * by pos.  In other words, inserting s2 at position 0 (the first
 * character of a string) in s1 is equivalent to the string s2
 * followed by string s1.
 * 
 * If the character position pos is higher (or equivalent to) the
 * length of string s1, s2 will simply be appended to the end of s1
 * (i.e. it is equivalent to my_strcat(s1, s2);
 * 
 * Example: char foo[10] = "foo";
 * my_strinsert(foo, "bar", 0) yields "barfoo".
 * 
 * Example(2): char foo[10] = "foo";
 * my_strinsert(foo, "bar", 100) yields "foobar".
 */

void my_strinsert(char *s1, const char *s2, int pos)//Function to insert one string into another from a specific position
{
  int a = my_strlen (s1);
  if (pos >= a)//If the position asked is great than the length of the string s1
  {
     my_strcat(s1, s2);
  }

  else
  { int b = my_strlen (s2); 
    int i;
    int j;
    int k;

    for (i = a; i >= pos; i--)//Transferring string elements to the end
    {
       s1[i+b] = s1[i];
    }
    for (j = pos, k = 0; k < b; j++, k++)//Entering elements of s2 into s1
    {
       s1[j] = s2[k];
    }
  }
  
}

/**
 * Delete a portion of the null-terminated string s that starts at
 * character position pos and is length characters long.  All
 * characters following position pos + length in s will be moved up to
 * follow directly after the characters before position pos. 
 * 
 * Hint: there is no need to create any temporary memory; simply copy
 * the contents of the string after position pos + length to their new
 * location.
 * 
 * Deletions should happen BEFORE the character position referenced by
 * pos.  In other words, deleting position 0 (the first character of a
 * string) in s means will start deleting from the first character.
 *
 * If the character position pos is higher (or equivalent to) the
 * length of string s, the function will do nothing.
 * 
 * If the length of the deleted portion from its starting position pos
 * extends past the end of the string, the remainder of the string
 * will be deleted.
 * 
 * Example: char foo[10] = "foobar";
 * my_strdelete(foo, 3, 3) yields "foo".
 *
 * Example(2): char foo[10] = "foobar";
 * my_strdelete(foo, 0, 3) yields "bar".
 * 
 * Example(3): char foo[10] = "foobar";
 * my_strdelete(foo, 0, 34) yields "".
 * 
 * Example(4): char foo[10] = "foobar";
 * my_strdelete(foo, 2, 30) yields "fo";
 */
void my_strdelete(char *s, int pos, int length)//Function to delete a specific part of a string
{
  int a = my_strlen (s);
  if (length > a)//if the length given is greater than length of the string s
    s[pos] = '\0';

  int i;
  int j;
  for (i = pos, j = length; j <= a; i++, j++)//Loop to copy elements present after the deleted spot
  {
    s[i] = s[j];
  }
  s[j] = '\0';//Ending the array with NULL 
}


   


