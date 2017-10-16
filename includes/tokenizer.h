#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <string>
#include "../includes/I_tokenizer_stratergy.h"
#include "default_tokenizer_stratergy.h"
#include <ostream>



/**
 * The class responsible of breaking up a string of words into tokens.
 * It does so by using a provided tokenizing stratergy. if there is not 
 * a statergy that is provided, a default stratergy will be used.
 * The tokenizer class is responsible of mangining the lifetime of a given stratergy.
 * @see I_tokenizer_stratergy
 * @see default_tokenizer_stratergy
 */
class tokenizer
{
public:

	/**
	* Allows to print debug information about the tokenizer instance.
	* @param out The ouput stream.
	* @param tokenizer The tokenizer instance.
	* @return std::ostream& operator the output stream.
	*/
	friend std::ostream& operator<<(std::ostream& out, const tokenizer& o);

	/**
	* Creates a new instance of tokenizer. 
	* @param strat The tokenizing stratergy to use. if none specified, the
	* default stratergy will be used.
	* @see default_tokenizer_stratergy
	*/
	tokenizer(I_tokenizer_stratergy * strat = new default_tokenizer_stratergy());
	/**
	* Deconstruct the tokenizer instance, freeing the stratergy.
	*/
	~tokenizer();
	/**
	* Break up a string of words into a collection of tokens.
	* @param text The text to be tokenized.
	* @return std::vector<std::string> a collection of tokens.
	*/
	std::vector<std::string> tokenize(const std::string& text);
	/**
	* Allows to specify a new statergy to be used.
	* Note: The previous stratergy will be freed.
	* @param strat The new stratergy to be used to tokenize.
	*/
	void setTokenizerStratergy(I_tokenizer_stratergy * strat);
private:
	I_tokenizer_stratergy * stratergy;
};

#endif // TOKENIZER_H