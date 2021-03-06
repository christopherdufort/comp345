
#ifndef STOPWORD_H
#define STOPWORD_H

#include <string>
#include <unordered_map>

/**
 * Class used to filter stopwords based on a list of stopwords given
 * at instatioation
 */
class StopWord {
  /**
   *  @brief Operator overload for debug output 
   * 
   * 
   * @param stream The output stream to write to
   * @param sw the StopWord object to read from
   * 
   * @return std::ostream
   */
  friend std::ostream& operator<<(std::ostream& stream, StopWord& sw);
public:
  /**
   * @brief default constructor for StopWord
   * Creates an empty StopWord object
   */
  StopWord(); 
  /**
   * @brief Creates a StopWord object from a file
   * 
   * Builds a stopword object based off a file of stopwords
   * ( this file is either a newline or comma delimited list)
   * 
   * @param fileName The name of the file containing the stopwords
   */
  StopWord(std::string fileName);
  /**
   * @brief Checks if a word is a stopword
   * 
   * Operator overload that checks if a specific word is a 
   * stopword
   * 
   * @param word The word to check
   * 
   * @return true if a word is a stopword
   * @return false if a word is not a stopword
   */
  bool operator()(std::string word);
private:
  std::unordered_map<std::string, bool> stopWords;/**The list of stopwords*/
};

#endif
