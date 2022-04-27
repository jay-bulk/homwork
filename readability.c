#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

float count_L(string text);
float count_W(string text);
float count_S(string text);


int main(void)
{
// Read In Input
    string text = get_string("Text: ");
// index = 0.0588 * L - 0.296 * S - 15.8 this is the scholastic function to determine grade average
// string text = "It was a bright cold day in April, and the clocks were striking thirteen. Winston Smith, his chin nuzzled into his breast in an effort to escape the vile wind, slipped quickly through the glass doors of Victory Mansions, though not quickly enough to prevent a swirl of gritty dust from entering along with him.";
//Count Letters(LC)
    float LC =  count_L(text);
// Count Sentences(SC)
    float SC = count_S(text);
// Count Words(WC)
float WC = count_W(text);
// W is the number of 100s of words in the text
// float W = WC;
// L is the average number of letters per 100 words in the text
float L = 100 * (LC / WC);
// S is the average number of sentencess per 100 words in the text
float S = 100 * (SC / WC);

// Index = 0.0588 * L - 0.296 * S - 15.8

float index = round(0.0588 * L - 0.296 * S - 15.8);

//printf("Average WC = %f, LC per 100W = %f, SC per 100W = %f",W,L,S);
//printf("Index total was: %f\n", index);

if(index > 16)
{
    printf("Grade 16+\n");
}
else if (index < 1)
{
    printf("Before Grade 1\n");
}
else
{
    printf("Grade %i\n", (int) index);
}

}

float count_L(string text)
{
    float LC = 0;
    for(int i = 0; i < strlen(text); i++)
    {
        if(isalpha(text[i]))
        {
            LC += 1;
           // printf("L is %f\n",LC);
        }
    }
    return LC;
}

float count_W(string text)
{
    float WC = 1;
    for(int i = 0; i < strlen(text); i++)
    {
        if(text[i] == ' ' && text[i+1] != ' ')
        {
            WC += 1;
          //  printf("WC is %f\n", WC);
        }
    }
    return WC;
}

float count_S(string text)
{
    float SC = 0;
    for(int i = 0; i < strlen(text); i++)
    {
        if(text[i] == '.' || text[i] == '?' || text[i] == '!' )
        {
            SC +=1;
         //   printf("SC is %f\n", SC);
        }
        // It's highly unlikely a sentenc will end in two characters there this is to avoid double counting a triple ... as opposed to a single .
    }
    return SC;
}
