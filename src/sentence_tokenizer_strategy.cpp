#include <algorithm>

#include "../includes/sentence_tokenizer_strategy.h"

SentenceTokenizerStrategy::SentenceTokenizerStrategy(std::vector<std::string> abr, const std::string &delimiters)
    : abreviations(abr), delimiters(delimiters) {}

SentenceTokenizerStrategy::~SentenceTokenizerStrategy() {}

std::vector<std::string> SentenceTokenizerStrategy::tokenize(const std::string &text)
{
  size_t current = 0;
  size_t next = -1;
  std::vector<std::string> words;
  do
  {
    size_t current = 0;
    size_t next = -1;
    std::vector<std::string> words;
    std::string currentsentence = "";
    do
    {
      current = next + 1;
      next = text.find_first_of(this->delimiters, current); // go until sentence terminating punctuation is reached
      currentsentence += text.substr(current, next - current);
      std::transform(currentsentence.begin(), currentsentence.end(), currentsentence.begin(), tolower);
      std::string lastWord = currentsentence.substr(currentsentence.find_last_of(" \t"), currentsentence.length - 1);
      if (std::find(abreviations.begin(), abreviations.end(), lastWord)) 
      
      if (currentsentence == "")
        continue;
  
      words.push_back(currentsentence);
  
    } while (next != std::string::npos);
  
    return words;
}
