#ifndef DEFAULT_TOKENIZER_strategy_H
#define DEFAULT_TOKENIZER_strategy_H

#include <string>
#include <vector>

#include "I_tokenizer_strategy.h"

class SentenceTokenizerStrategy : public I_tokenizer_strategy {
public:
  SentenceTokenizerStrategy(std::vector<std::string> abr, const std::string &delimiters = " ,\t-':!().?\";–—~{}/*\n\t\r");
  virtual ~SentenceTokenizerStrategy();
  virtual std::vector<std::string> tokenize(const std::string &text);
private:
  std::vector<std::string> abreviations;
  std::string delimiters;
};

#endif