typedef struct NO *ArvBin;

ArvBin *criar_arvore();

int inserir_arvore(ArvBin *, int);

void em_ordem(ArvBin *);

int maior_numero(ArvBin *);

int total_folha(ArvBin *);

int n_menor_valor(ArvBin *, int);

