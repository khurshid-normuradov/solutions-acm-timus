#include <cassert>
#include <iostream>  // бу std::cin,  std::cout -- маълумотларни укиш ва ёзиш учун керак.
#include <string>      //  std::string  -  стандарт сатр структураси
#include <vector>     //  std::vector  - стандарт динамик массив.
#include <queue>


//  бу функция  сузларни ракамлар кетма-кетлигига айлантиради. 
std::string word_to_digits( std::string word )
{
     std::string digits( word.length(), '0' ) ;

     for(size_t i= 0; i < word.length(); ++i)
     {
              switch(word[i] )
             {
                       case 'i'   : case 'j'                 :    digits[i] = '1'; break;
                       case 'a'  : case 'b': case 'c'   :    digits[i] = '2'; break;
                       case 'd'  : case 'e': case 'f'    :    digits[i] = '3'; break;
                       case 'g'  : case 'h'                :    digits[i] = '4'; break;
                       case 'k'  : case 'l'                 :    digits[i] = '5' ; break;
                       case 'm' : case 'n'                :    digits[i] = '6'; break;
                       case 'p'  : case 'r' : case 's'   :    digits[i] = '7'; break;
                       case 't'   : case 'u' : case 'v'  :    digits[i] = '8'; break;
                       case 'w' : case 'x' : case 'y'  :    digits[i] = '9' ; break;
                       case 'o'  : case 'q' : case 'z'  :    digits[i] = '0'; break;
                       default:  assert(false); break;
             }
     }
     return digits;
}

int main()
{
   // бизнинг digits  структурамиз.
    std::string digits;

// масала шартига кура, файлда бир ёки бир канча тестлар берилади,шунинг учун цикл очамиз.
    while (   std::cin >> digits )
    {
             if ( digits == "-1" )  break; // Агар -1 киритилса, тестлар тугаган булади.
             

             assert( digits.size() >0 && digits.size() < 101);

             for(size_t i = 0; i < digits.length(); ++i)
                     assert( digits[i] >='0' && digits[i] <='9');

           // matches массивини эълон киламиз ва уни -1 билан тулдирамиз.
            int matches[ 101 ][ 101 ] ;

             for(int i= 0; i < 101; ++i)
                   for(int j = 0; j < 101; ++j) matches[i][j] = -1;

            // cузлар массивини укиб оламиз, ва йул-йулакай matches ни хам тулдириб борамиз.
             std::vector< std::string > words;
             int nword;
         
             std::cin >> nword;
           
             assert( nword >= 0 && nword <= 50 * 1000 );

             for(int i_word = 0; i_word< nword ; ++i_word)
             {
                      std::string word; // янги суз
                     std::cin >> word;
                   
                     std::string word_as_digits = word_to_digits(word);
                     
                   
  if ( word.length() <= digits.length() )
  {
                      for( size_t i = 0;  i <  digits.length() - word.length() + 1; ++i)
                        if (   digits.compare(  i, word.length(),  word_as_digits) == 0 )
                                  matches[ i ] [ i + word.length() - 1] = i_word;
                    }
                // cузни массивга соламиз.
                 words.push_back(word);
              }
         

           // Энди асосий хисоблашни бошлаймиз.
           
           
             std::queue<int> queue;
             std::vector<int> prev( digits.length() + 1 ,   -2); // бизга 1 та ортикча элемент керак булади.
             queue.push(0); // бизда, яъни С++ да  0 - бу 1-позиция :))
             prev[0] = -1;
           
            while(  ! queue.empty() )
             {
                       int i = queue.front();  // очереддаги навбатдаги позицияни оламиз.
                       queue.pop();   // олинган сонни эса очереддан учирамиз.
                     
                       // шу позициядан бошлаб digits нинг охиргача барча позицияларни текширамиз. 
                       for(size_t j = i; j < digits.size() ; ++j)
                      {
                         if (  matches[ i ] [ j ] != -1  && prev[ j + 1] < 0 )
                         {
                                  queue.push(j+1);
                                  prev[ j + 1] = i;
                         }
                      }
              }
           
         // Агар prev[ m ]  < 0   булса, ечим йук.
          if (  prev[digits.length() ] < 0 )
           {
                   std::cout << "No solution." << std::endl;
                   continue;
           }
         
          // indexes массивини оламиз ва уни тулдирамиз.
           std::vector<int> indexes;
           int m = digits.length();
           while ( prev[m] >= 0 )
           {
 int prev_m = prev[ m ];
                 indexes.push_back( matches[ prev_m ][ m - 1] );
                 m = prev[m];
           }
         
          //  indexes массив элементлар сони
           int k = indexes.size();

            assert( k > 0 );

           // тескари тартибда чоп этамиз.
           for(int i = k-1; i >=0; --i)
           {
                    std::cout << words[ indexes[ i ]  ];
                    if ( i > 0 ) std::cout << ' ';
           }
            std::cout << std::endl;
    }     // end while

   return 0;
} // end main
