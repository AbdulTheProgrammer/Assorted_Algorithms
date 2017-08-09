//
//  convert_words_to_number.c
//  
//
//  Created by Md Tahsin Sharif on 2017-08-08.
//
//

//LOOKUP TABLES
// given a number like "one hundred ninety six", convert it to its corresponding number = 196
static readonly Dictionary<string, byte> dic1 = new Dictionary<string, byte> {
    { "one", 1 }, { "two", 2 }, { "three", 3 }, { "four", 4 }, { "five", 5 },
    { "six", 6 }, { "seven", 7 }, { "eight", 8 }, { "nine", 9 },{ "ten", 10 },
    { "eleven", 11 }, { "twelve", 12 }, { "thirteen", 13 }, { "fourteen", 14 },
    { "fifteen", 15 }, { "sixteen", 16 }, { "seventeen", 17 },{ "eighteen", 18 },
    { "nineteen", 19 }, { "twenty", 20 }, { "thirty", 30 }, { "forty", 40 },
    { "fifty", 50 }, { "sixty", 60 },{ "seventy", 70 },{ "eighty", 80 },{ "ninety", 90 }
};


static readonly Dictionary<string, byte> dict2 = new Dictionary<string, byte> {
    { "thousand", 3 },{ "million", 6 }, { "billion", 9 },
    { "trillion", 12 }, {"hundred", 2} // any more if needed
};

//Abdulhadi's Python implementation
array = string.split(' ')
int first = True;
int first_look = 0
int second_look = 0
int value = 0;

for word in array:
   if dic1[word] != None:
      first_look += dic1[word]
   else if dic2[word] != None:
      second_look = dic2[word]
      value += first_look * (10 ** second_look)
      first_look = 0
      second_look = 0
   else:
      print "No"

value += first_look
