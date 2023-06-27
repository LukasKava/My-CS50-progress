#include <cs50.h>
#include <stdio.h>
#include <math.h>

/**
 * FUNCTION: (count_letters) counts
 *              how many letters there are
 *              in any given string.
 */
int count_letters(char *text)
{
    int amount_letters;

    amount_letters = 0;
    for (int i  = 0; text[i] != '\0'; i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            amount_letters++;
        }
    }
    return (amount_letters);
}

/**
 * FUNCTION: (count_words) counts how many words
 *              there are in any given  string.
 */
int count_words(char *text)
{
    int words;

    words = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }
    }
    words++;
    return (words);
}

/**
 * FUNCTION: (count_sentences) counts how many
 *              sentences there are in any given
 *              block of text.
 */
int count_sentences(char *text)
{
    int sentence_count;

    sentence_count = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentence_count++;
        }
    }
    return (sentence_count);
}

int main(void)
{
    int     i;
    double      letters;
    double     words;
    double     sentences;
    double      L;
    double      S;
    double     grade;
    char    *input_text;

    i = 0;
    input_text = get_string("Text: ");
    letters = count_letters(input_text);
    words =  count_words(input_text);
    sentences = count_sentences(input_text);

    //After counting the parameters we need.
    //It further counts L and S which are.
    //L average number of letters per 100 words in the text.
    //S average number of sentences per 100 words in the text.
    L = (letters / words * 100);
    S = (sentences / words * 100);

    //grade is the Coleman-Liau index which calculates
    //what US grade the given text is.
    grade = (0.0588 * L) - (0.296 * S) - 15.8;
    if (grade > (int)grade + 0.5)
    {
        grade++;
    }

    //Printing the needed info.
    if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %d\n", (int)grade);
    }
    return (0);
}