void vPop(int* ipStack, int iValor);
void vDeleteStack(int* ipStack);

int* ipStack (int iTamanho);
int vPush(int* ipStack, int iValor);
int vTop(int* ipStack);

bool vIsEmpty(int* ipStack);
bool iCheckStackOverflow(int* ipStack);
bool iCheckStackUnderflow(int* ipStack);

/**
 * Função que verifica se as pilhas estão vazias
*/

bool vIsEmpty(int* ipStack) {
    if (ipStack[2] == NULL) {
        return true;
    }

    return false;
}

/**
 * Função que verifica o topo das pilhas
*/

int vTop(int* ipStack) {
    int iUltimaPosicao;

    iUltimaPosicao = (ipStack[0] - 1);

    if (ipStack[0] != 0) {
        return ipStack[iUltimaPosicao];
    }

    return -1;
}

/**
 * Função que verifica StackOverflow nas pilhas
*/

bool iCheckStackOverflow(int* ipStack)
{
    int iTamanhoAtual, iTamanhoLimite;
  
    iTamanhoAtual = ipStack[0];
    iTamanhoLimite = ipStack[1];

    iTamanhoAtual -= 2;

    if ((iTamanhoAtual + 1) > iTamanhoLimite) {
        return true;
    }
    
    return false;
}

/**
 * Função que adiciona elementos nas pilhas
*/

int vPush(int* ipStack, int iValor) 
{
    int iContador = ipStack[0], iPosicaoAtual;

    if (iCheckStackOverflow(ipStack) == false && ipStack[0] != NULL) {
        iPosicaoAtual = ipStack[0];
        ipStack[iPosicaoAtual] = iValor;
        ipStack[0] = iContador += 1;
    } else {
        Serial.println("StackOverflow, valor não inserido!");
        return 0;
    }

    return 1;
}

/**
 * Função que deleta as pilhas
*/

void vDeleteStack(int* ipStack)
{
    free(ipStack);

    for (int i=1; ipStack[i] != NULL; i++) {
        ipStack[i] = NULL;
    }

    ipStack = NULL;
}

/**
 * Função que cria as pilhas
*/

int* ipStack(int iTamanho)
{
    int* ipBytesMemoria;
    int iTamanhoPilha;

    iTamanhoPilha = ((iTamanho + 2) * sizeof(int));
    ipBytesMemoria = (int* ) malloc(iTamanhoPilha);
    ipBytesMemoria[0] = 2;
    ipBytesMemoria[1] = iTamanho;

    return ipBytesMemoria;
}
