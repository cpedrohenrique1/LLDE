#include "llde.h"

Pedro::llde::llde() : quantidadeElementos(0),
                      inicio(0),
                      fim(0)
{
}

bool Pedro::llde::estaVazia() const
{
    return !((bool)quantidadeElementos);
}

void Pedro::llde::inserirInicio(int entrada)
{
    try
    {
        no *aux = new no(entrada);
        if (estaVazia())
        {
            inicio = fim = aux;
            quantidadeElementos++;
            return;
        }
        inicio->setAnterior(aux);
        aux->setProximo(inicio);
        inicio = aux;
        quantidadeElementos++;
    }
    catch (std::bad_alloc &erro)
    {
        throw QString("Nao foi possivel alocar memoria - inserirInicio");
    }
}

QString Pedro::llde::obterDados() const
{
    if (estaVazia())
    {
        return "(lista esta vazia)";
    }
    QString resultado = "";
    no *aux = inicio;
    for (int i = 0; i < quantidadeElementos; i++)
    {
        if (i == 0)
        {
            resultado += "|" + QString::number(aux->getDado()) + "|";
        }
        else
        {
            resultado += " -> |" + QString::number(aux->getDado()) + "|";
        }
        aux = aux->getProximo();
    }
    return resultado;
}

int Pedro::llde::getQuantidadeElementos() const
{
    return quantidadeElementos;
}

void Pedro::llde::inserirOrdenado(int entrada)
{
    if (estaVazia())
    {
        inserirInicio(entrada);
        return;
    }
    no* aux = inicio;
    int indice = 0;
    for (int i = 0; i < quantidadeElementos; i++)
    {
        if (entrada > aux->getDado())
        {
            indice = i + 1;
        }
        aux = aux->getProximo();
    }
    inserirPosicao(indice, entrada);
}

int Pedro::llde::acessarInicio() const
{
    if (estaVazia())
    {
        throw QString("Nao foi possivel acessar, lista vazia");
    }
    return inicio->getDado();
}

int Pedro::llde::retirarInicio()
{
    if (estaVazia())
    {
        throw QString("Nao foi possivel retirar, lista ja vazia");
    }
    if (quantidadeElementos == 1)
    {
        no* aux = inicio;
        quantidadeElementos = 0;
        fim = inicio = 0;
        int valor = aux->getDado();
        delete aux;
        return valor;
    }
    int valor = inicio->getDado();
    no *aux = inicio;
    inicio = inicio->getProximo();
    inicio->setAnterior(0);
    delete aux;
    quantidadeElementos--;
    return valor;
}

void Pedro::llde::inserirFim(int entrada)
{
    if (estaVazia())
    {
        inserirInicio(entrada);
        return;
    }
    try
    {
        no *aux = new no(entrada);
        fim->setProximo(aux);
        aux->setAnterior(fim);
        fim = aux;
        quantidadeElementos++;
    }
    catch (std::bad_alloc &erro)
    {
        throw QString("Nao foi possivel alocar memoria");
    }
}

int Pedro::llde::acessarFim() const
{
    if (estaVazia())
    {
        throw QString("Nao foi possivel acessar, lista vazia");
    }
    return fim->getDado();
}

int Pedro::llde::retirarFim()
{
    if (estaVazia())
    {
        throw QString("Nao foi possivel retirar, lista ja vazia");
    }
    if (quantidadeElementos == 1)
    {
        no* aux = fim;
        quantidadeElementos = 0;
        inicio = fim = 0;
        int valor = aux->getDado();
        delete aux;
        return valor;
    }
    no *aux = fim;
    int valor = fim->getDado();
    fim = fim->getAnterior();
    fim->setProximo(0);
    delete aux;
    quantidadeElementos--;
    return valor;
}

void Pedro::llde::inserirPosicao(int posicao, int entrada)
{
    if (posicao < 0 || posicao > quantidadeElementos)
    {
        throw QString("Posicao invalida");
    }
    if (estaVazia() || posicao == 0)
    {
        inserirInicio(entrada);
        return;
    }
    if (posicao == quantidadeElementos)
    {
        inserirFim(entrada);
        return;
    }
    try
    {
        no *novo = new no(entrada);
        no* aux;
        if (posicao < quantidadeElementos / 2)
        {
            aux = inicio;
            for (int i = 0; i < posicao; i++)
            {
                aux = aux->getProximo();
            }
        }
        else
        {
            aux = fim;
            for (int i = quantidadeElementos - 1; i > posicao; i--)
            {
                aux = aux->getAnterior();
            }
        }
        no *anterior = aux->getAnterior();
        anterior->setProximo(novo);
        novo->setAnterior(anterior);
        novo->setProximo(aux);
        aux->setAnterior(novo);
        quantidadeElementos++;
    }
    catch (std::bad_alloc &erro)
    {
        throw QString("Nao foi possivel alocar memoria");
    }
}

int Pedro::llde::acessarPosicao(int posicao) const
{
    if (posicao < 0 || posicao >= quantidadeElementos)
    {
        throw QString("Posicao invalida");
    }
    if (estaVazia())
    {
        throw QString("Lista vazia");
    }
    if (posicao == 0)
    {
        return acessarInicio();
    }
    if (posicao == quantidadeElementos - 1)
    {
        return acessarFim();
    }
    if (posicao < quantidadeElementos / 2)
    {
        no *aux = inicio;
        for (int i = 0; i < posicao; i++)
        {
            aux = aux->getProximo();
        }
        return aux->getDado();
    }
    else
    {
        no *aux = fim;
        for (int i = quantidadeElementos - 1; i > posicao; i--)
        {
            aux = aux->getAnterior();
        }
        return aux->getDado();
    }
}

int Pedro::llde::retirarPosicao(int posicao)
{
    if (estaVazia())
    {
        throw QString("Lista ja vazia");
    }
    if (posicao < 0 || posicao >= quantidadeElementos)
    {
        throw QString("Posicao invalida");
    }
    if (posicao == quantidadeElementos - 1)
    {
        return retirarFim();
    }
    if (posicao == 0)
    {
        return retirarInicio();
    }
    no* aux;
    if (posicao < quantidadeElementos / 2)
    {
        aux = inicio;
        for (int i = 0; i < posicao; i++)
        {
            aux = aux->getProximo();
        }
    }
    else
    {
        aux = fim;
        for (int i = quantidadeElementos - 1; i > posicao; i--)
        {
            aux = aux->getAnterior();
        }
    }
    no *anterior = aux->getAnterior();
    no *proximo = aux->getProximo();
    anterior->setProximo(proximo);
    proximo->setAnterior(anterior);
    int valor = aux->getDado();
    delete aux;
    quantidadeElementos--;
    return valor;
}
