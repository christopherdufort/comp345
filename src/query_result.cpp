#include "../includes/query_result.h"

query_result::query_result(IndexItem* idxItem, double score) : idxItem(idxItem), score(score)
{

}

IndexItem* query_result::getItem() const
{
	return idxItem;
}

double query_result::getScore() const
{
	return score;
}
