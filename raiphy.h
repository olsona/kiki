#ifndef _RAIPHY_H_
#define _RAIPHY_H_

typedef struct {
  int kmerSize;
  long long ** count;
} kmer_freq_t;
  
kmer_freq_t* kiAllocKmerFreq(int kmerSize);
kmer_freq_t* kiFreeKmerFreq(kmer_freq_t* freq);
void kiClearKmerFreq(kmer_freq_t* freq);
void kiScanSeqsForFreq(alignment_t* seqs, kmer_freq_t* freq);
void kiScanFastaForFreq(char* fileName, kmer_freq_t* freq);
void kiFreqToRaiVectorOriginal(kmer_freq_t* freq, double* vector);

void kiFreqToRaiVector(kmer_freq_t* freq, double* vector);


typedef struct {
  int nameLen;
  int kmerSize;
  int nClass;
  int nDim;
  int nSaved;
  char** names;
  double** vectors;
} rai_db_t;

rai_db_t* kiAllocRaiDb(int kmerSize);
rai_db_t* kiFreeRaiDb(rai_db_t* db);
void      kiRaiDbGrow(rai_db_t* db);
void      kiRaiDbAdd(rai_db_t* db, char* name, double* vector);
void      kiPrintRaiDb(FILE* fp, rai_db_t* db);
rai_db_t* loadDatabase(char* fileName);

typedef struct {
  double score;
  double index;
} score_pair;

int comp_score_pairs(const void *p1, const void *p2);

int       classifySequenceOriginal(char* seq, rai_db_t* db, double* margin);
//void       classifySequenceAll(char* seq, rai_db_t* db, double* scores);
void    classifySequenceAll(char* seq, rai_db_t* db, score_pair* scores);
void    classifySequenceTop(char* seq, rai_db_t* db, int num_match, double* scores, int* indices);
int       classifySequence(char* seq, rai_db_t* db, double* margin);

#endif /* _RAIPHY_H_ */


