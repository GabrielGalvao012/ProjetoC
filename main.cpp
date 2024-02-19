#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;
struct alunos{
    float cpf;
    char nomeAluno[30];
    char data_nascimento[9];
    float peso;
    float altura;
    int statusAluno;
    float imc;

};

struct ind_alunos{
    float cpf;
    int endAluno;
};

struct professores{
    int codigo_prof;
    char nomeProf[30];
    char endereco_prof[30];
    float telefone;
    int statusProf;
};

struct ind_professores{
    int codigo_prof;
    int endProf;
};

struct modalidades{
    int codigo_modalidade;
    char descricao[50];
    int codigo_prof;
    float valor_aula;
    int limite_alunos;
    int total_alunos;
    int statusModalidade;
};

struct ind_modalidades{
    int codigo_modalidade;
    int endModalidade;
};

struct matriculas{
    int codigo_matricula;
    float cpf;
    int codigo_modalidade;
    int quantidade_aula;
    int statusMatricula;
};

struct ind_matriculas{
    int codigo_matricula;
    int endMatricula;
};

int verificarProfessor(struct professores professorA[], int codA, int contadorProfessorA){
    int i = 0, f = contadorProfessorA;
    int m=(i+f)/2;
    int professorEncontrado;

    for(; f>= i && codA != professorA[m].codigo_prof; m = (i + f)/2){
        if(codA > professorA[m].codigo_prof)
            i = m + 1;
        else
            f = m - 1;
    }
    if(codA == professorA[m].codigo_prof){
        cout<<"\n\tEncontro professor...";
        cout<<"\n\tNome do professor: "<<professorA[m].nomeProf;
        cout<<"\n\tTelefone: "<<professorA[m].telefone;
        professorEncontrado = professorA[m].codigo_prof;
        return m;
    }
    else {
        return - 1;
    }
}

int verificarAluno(struct alunos alunoA[], float codB, int contadorAlunoA, struct ind_alunos indiceAlunoA[]){
    int i = 0, f = contadorAlunoA;
    int m = (i+f)/2;
    float alunoEncontrado;
    for(;f>= i && codB != alunoA[m].cpf; m = (i + f)/2){
        if(codB > alunoA[m].cpf)
            i = m + 1;
        else
            f = m -1;
    }

    if(codB == alunoA[m].cpf){

        int i=0; //INDICE
        int j=0;//ENDERECO DO INDICE
        for(; j<=contadorAlunoA; j++){

            i = indiceAlunoA[j].endAluno;

            if(alunoA[i].statusAluno == 1 ){


                cout<<"\n\tAluno encontrado..";
                cout<<"\n\tNome do aluno: "<<alunoA[m].nomeAluno;
                alunoEncontrado = alunoA[i].cpf;

                if(alunoA[i].imc < 17){
                    cout<<"\nMuito abaixo do peso ideal"<<endl;
                    cout<<alunoA[i].peso<<" kg";
                    cout<<"\nIMC: "<< alunoA[i].imc;
                }
                else if(alunoA[i].imc > 17 && alunoA[i].imc < 18.49){
                    cout<<"\nAbaixo do peso ideal"<<endl;
                    cout<<alunoA[i].peso<<" kg";
                    cout<<"\nIMC: "<< alunoA[i].imc;
                }
                else if(alunoA[i].imc > 18.5 && alunoA[i].imc < 24.99){
                    cout<<"\nPeso normal"<<endl;
                    cout<<alunoA[i].peso<<" kg";
                    cout<<"\nIMC: "<< alunoA[i].imc;
                }
                else if(alunoA[i].imc > 25 && alunoA[i].imc < 29.99){
                    cout<<"\nAcima do peso"<<endl;
                    cout<<alunoA[i].peso<<" kg";
                    cout<<"\nIMC: "<< alunoA[i].imc;
                }
                else if(alunoA[i].imc > 30 && alunoA[i].imc < 34.99){
                    cout<<"\nObesidade I"<<endl;
                    cout<<alunoA[i].peso<<" kg";
                    cout<<"\nIMC: "<< alunoA[i].imc;
                }
                else if(alunoA[i].imc > 35 && alunoA[i].imc < 39.99){
                    cout<<"\nObesidade II (SEVERA)"<<endl;
                    cout<<alunoA[i].peso<<" kg";
                    cout<<"\nIMC: "<< alunoA[i].imc;
                }
                else{
                    cout<<"\nObesidade III (MORBIDA)"<<endl;
                    cout<<alunoA[i].peso<<" kg";
                    cout<<"\nIMC: "<< alunoA[i].imc;
                }
            }
        }

        return m;
    }
    else {
        return - 1;
    }
}
int verificarModalidade(struct modalidades modalidadeA[], int codC, int contadorModalidadeA){
    int i = 0, f = contadorModalidadeA;
    int m = (i+f)/2;
    int modalidadeEncontrada;
    for(;f>= i && codC != modalidadeA[m].codigo_modalidade; m = (i + f)/2){
        if(codC > modalidadeA[m].codigo_modalidade)
            i = m + 1;
        else
            f = m -1;
    }
    if(codC == modalidadeA[m].codigo_modalidade){
        cout<<"\n\tModalidade encontrada..";
        cout<<"\n\tDescricao: "<<modalidadeA[m].descricao;
        modalidadeEncontrada = modalidadeA[m].codigo_modalidade;
        return m;
    }}

///ALUNO
void inserir_aluno(struct alunos alunoB[], struct ind_alunos indiceAlunoA[],int &contadorAlunoB, float codD){				//INCLUIR ALUNO
    float peso;
    float altura;
    float imc;
    contadorAlunoB++;
    alunoB[contadorAlunoB].cpf = codD;
    cout<<"\nInserir novo aluno";
    cout<<"\nCPF do aluno: "<<alunoB[contadorAlunoB].cpf;
    cout<<"\nDigite o nome: ";
    cin>>alunoB[contadorAlunoB].nomeAluno;
    cout<<"\nDigite a data de nascimento: ";
    cin>>alunoB[contadorAlunoB].data_nascimento;
    cout<<"\nDigite o peso: ";
    cin>>peso;
    alunoB[contadorAlunoB].peso = peso;
    cout<<"\nDigite a altura: ";
    cin>>altura;
    alunoB[contadorAlunoB].altura = altura;
    alunoB[contadorAlunoB].statusAluno=1;
    imc = peso/(altura*altura);
    alunoB[contadorAlunoB].imc = imc;
    cout<<"----------------------------------------------------"<<endl;


    int i;
    for (i = contadorAlunoB - 1; indiceAlunoA[i].cpf > codD; i--){
        indiceAlunoA[i+1].cpf = indiceAlunoA[i].cpf;
        indiceAlunoA[i+1].endAluno = indiceAlunoA[i].endAluno;
    }
    indiceAlunoA[i+1].cpf = codD;
    indiceAlunoA[i+1].endAluno = contadorAlunoB;
    cout << "\n\nInclusao realizada com Sucesso..."<< endl;
    getch();
    cout<< "\n\nTecle algo para Retornar..."<<endl;
}

void buscaAluno (struct ind_alunos indiceAlunoB[], struct alunos alunoC[], int &contadorAlunoC, float codE){
    int saida = 1;			//bUSCA ALUNO PARA INCLUIR
    int i = 0, f = contadorAlunoC-1, r=0;
    int m = (i + f) / 2;
    for (;  saida != 0 && f >= i && codE != indiceAlunoB[m].cpf; m = (i + f) / 2){
        if (codE > indiceAlunoB[m].cpf)
            i = m + 1;
        else
            f = m - 1;
    }
    if (codE == indiceAlunoB[m].cpf){
        cout << "\n\nAluno ja Cadastrado - nao pode ser cadastrado novamente";
        i = indiceAlunoB[m].endAluno;
        cout << "\nCPF do aluno: " << alunoC[i].cpf;
        cout << "\nNome: " << alunoC[i].nomeAluno;
        cout << "\nData de nascimento: "<< alunoC[i].data_nascimento;
        if(alunoC[i].imc < 17){
            cout<<"\nMuito abaixo do peso ideal"<<endl;
            cout<<alunoC[i].peso<<" kg";
            cout<<"\nIMC: "<< alunoC[i].imc;
        }
        else if(alunoC[i].imc > 17 && alunoC[i].imc < 18.49){
            cout<<"\nAbaixo do peso ideal"<<endl;
            cout<<alunoC[i].peso<<" kg";
            cout<<"\nIMC: "<< alunoC[i].imc;
        }
        else if(alunoC[i].imc > 18.5 && alunoC[i].imc < 24.99){
            cout<<"\nPeso normal"<<endl;
            cout<<alunoC[i].peso<<" kg";
            cout<<"\nIMC: "<< alunoC[i].imc;
        }
        else if(alunoC[i].imc > 25 && alunoC[i].imc < 29.99){
            cout<<"\nAcima do peso"<<endl;
            cout<<alunoC[i].peso<<" kg";
            cout<<"\nIMC: "<< alunoC[i].imc;
        }
        else if(alunoC[i].imc > 30 && alunoC[i].imc < 34.99){
            cout<<"\nObesidade I"<<endl;
            cout<<alunoC[i].peso<<" kg";
            cout<<"\nIMC: "<< alunoC[i].imc;
        }
        else if(alunoC[i].imc > 35 && alunoC[i].imc < 39.99){
            cout<<"\nObesidade II (SEVERA)"<<endl;
            cout<<alunoC[i].peso<<" kg";
            cout<<"\nIMC: "<< alunoC[i].imc;
        }
        else{
            cout<<"\nObesidade III (MORBIDA)"<<endl;
            cout<<alunoC[i].peso<<" kg";
            cout<<"\nIMC: "<< alunoC[i].imc;
        }
        getch();
        cout<< "\n ";
    }
    else
        inserir_aluno (alunoC, indiceAlunoB, contadorAlunoC, codE);
    return;

}

void buscaAlunoExclusao (struct ind_alunos indiceAlunoC[], struct alunos alunoD[], int &contadorAlunoD, float codF){
    int saida = 1;
    int i = 0, f = contadorAlunoD, r=0;
    int m = (i + f) / 2;
    for (; f >= i && codF != indiceAlunoC[m].cpf; m = (i + f) / 2){
        if (codF >indiceAlunoC[m].cpf)
            i = m + 1;
        else
            f = m - 1;
    }
    if (codF == indiceAlunoC[m].cpf){
        i = indiceAlunoC[m].endAluno;
        if(alunoD[i].statusAluno == 1){
            cout<<"Irmao Ativo! Deseja realmente excluir o irmao?";
            cout<<"\nNome do irmao :"<<alunoD[i].nomeAluno;
            cout<<"\n\t0 - Sim  /  1 - Nao : ";
            cin>>r;
            if(r==0){
                alunoD[i].statusAluno = 0;
                cout<<"\n Irmao excluido com sucesso!"<< endl;
            }
            else{
                cout<<"Registro nao excluido";
            }
        }
    }
    else{
        cout<<"Registro nao existe";
    }
    getch();
}

void leituraExaustivaAluno(struct alunos alunoE[], struct ind_alunos indiceAlunoD[], int &contadorAlunoE){
    int i=0; //INDICE
    int j=0;//ENDERECO DO INDICE
    for(; j<=contadorAlunoE; j++){
        i= indiceAlunoD[j].endAluno;
        if(alunoE[i].statusAluno == 1 ){
            cout<<"\nRegistro existente...";
            cout<<"\nnome: "<<alunoE[i].nomeAluno;
            cout<<"\nData nascimento: "<<alunoE[i].data_nascimento<<endl;

            if(alunoE[i].imc < 17){
                cout<<"\n abaixo do peso ideal"<<endl;
                cout<<alunoE[i].peso<<" kg";
                cout<<"\nIMC: "<< alunoE[i].imc;
            }
            else if(alunoE[i].imc > 17 && alunoE[i].imc < 18.49){
                cout<<"\nAbaixo do peso ideal"<<endl;
                cout<<alunoE[i].peso<<" kg";
                cout<<"\nIMC: "<< alunoE[i].imc;
            }
            else if(alunoE[i].imc > 18.5 && alunoE[i].imc < 24.99){
                cout<<"\nPeso normal"<<endl;
                cout<<alunoE[i].peso<<" kg";
                cout<<"\nIMC: "<< alunoE[i].imc;
            }
            else if(alunoE[i].imc > 25 && alunoE[i].imc < 29.99){
                cout<<"\nAcima do peso"<<endl;
                cout<<alunoE[i].peso<<" kg";
                cout<<"\nIMC: "<< alunoE[i].imc;
            }
            else if(alunoE[i].imc > 30 && alunoE[i].imc < 34.99){
                cout<<"\nObesidade I"<<endl;
                cout<<alunoE[i].peso<<" kg";
                cout<<"\nIMC: "<< alunoE[i].imc;
            }
            else if(alunoE[i].imc > 35 && alunoE[i].imc < 39.99){
                cout<<"\nObesidade II (SEVERA)"<<endl;
                cout<<alunoE[i].peso<<" kg";
                cout<<"\nIMC: "<< alunoE[i].imc;
            }
            else{
                cout<<"\nObesidade III (MORBIDA)"<<endl;
                cout<<alunoE[i].peso<<" kg";
                cout<<"\nIMC: "<< alunoE[i].imc;
            }

            cout<< "\n ";
        }
        cout<<"-------------------------------------------------------"<<endl;
    }
}


void reorganizacaoAluno(struct alunos alunoF[],struct ind_alunos indiceAlunoE[], int contadorAlunoF,
                        struct alunos alunon[], struct ind_alunos indiceAlunon[], int &contadorAlunon){
    int i=0;
    int j=0;
    contadorAlunon=0;
    for(; j<=contadorAlunoF; j++ ){
        i=indiceAlunoE[j].endAluno;
        if(alunoF[i].statusAluno == 1){
            alunon[contadorAlunon].cpf=alunoF[i].cpf;
            strcpy(alunon[contadorAlunon].nomeAluno,alunoF[i].nomeAluno);
            strcpy(alunon[contadorAlunon].data_nascimento,alunoF[i].data_nascimento);
            alunon[contadorAlunon].peso=alunoF[i].peso;
            alunon[contadorAlunon].altura=alunoF[i].altura;
            alunon[contadorAlunon].statusAluno=alunoF[i].statusAluno;
            indiceAlunon[contadorAlunon].cpf=indiceAlunoE[j].cpf;
            indiceAlunon[contadorAlunon].endAluno=contadorAlunon;
            contadorAlunon++;
        }
    }
}

//void reorganizacaoAlunon(struct alunos alunon[],struct ind_alunos indiceAlunon[], int contadorAlunon,
//						 struct alunos alunoA[], struct ind_alunos indiceAlunoA[], int &contadorAlunoA){
//	contadorAlunoA=contadorAlunon -1;
//	alunoA = alunon;
//	indiceAlunoA = indiceAlunon;
//}





//PROFESSOR
void inserir_professor(struct professores professor[], struct ind_professores indiceProfessor[], int &contadorProfessor, int codP){// INCLUSAO DE PROFESSOR
    contadorProfessor++;
    professor[contadorProfessor].codigo_prof = codP;
    cout<<"\t\nInserir novo professor";
    cout<<"\nCodigo do professor: "<<professor[contadorProfessor].codigo_prof;
    cout<<"\nDigite o nome: ";
    cin>>professor[contadorProfessor].nomeProf;
    cout<<"\nDigite o endereco:";
    cin>>professor[contadorProfessor].endereco_prof;
    cout<<"\nDigite o telefone: ";
    cin>>professor[contadorProfessor].telefone;
    professor[contadorProfessor].statusProf=1;
    cout<<"-------------------------------------------------------"<<endl;

    int i;
    for(i = contadorProfessor -1; indiceProfessor[i].codigo_prof > codP; i--){
        indiceProfessor[i+1].codigo_prof = indiceProfessor[i].codigo_prof;
        indiceProfessor[i+1].endProf = indiceProfessor[i].endProf;

    }
    indiceProfessor[i+1].codigo_prof = codP;
    indiceProfessor[i+1].endProf = contadorProfessor;
    cout<<"\nInclusao realizado com sucesso"<< endl;
    getch();
    cout<<"\nTecle algo para Retornar..."<<endl;
}

void buscaProfessor (struct ind_professores indiceProfessor[], struct professores professor[],int &contadorProfessor, int codP){
    int saida =1;
    int i = 0, f = contadorProfessor-1, r=0;
    int m= (i + f) / 2;
    for(; saida !=0 && f>= i && codP != indiceProfessor[m].codigo_prof; m = (i + f) / 2){
        if (codP > indiceProfessor[m].codigo_prof){
            i = m + 1;
        }
        else{
            f = m - 1;
        }
    }
    if(codP == indiceProfessor[m].codigo_prof){
        cout<<"\nProfessor ja cadastrado - nao pode ser cadastrado novamente";
        i = indiceProfessor[m].endProf;
        cout<<"\n Codigo do professor: "<<professor[i].codigo_prof;
        cout<<"\n Nome: "<<professor[i].nomeProf;
        cout<<"\n Endereco: "<<professor[i].endereco_prof;
    }
    else
        inserir_professor(professor, indiceProfessor, contadorProfessor, codP);
}

void buscaProfessorExclusao (struct professores professor[], struct ind_professores indiceProfessor[],
                             int &contadorProfessor, int codP){

    int saida = 1;																									//BUSCA EXCLUSAO E EXCLUIR ALUNO
    int i = 0, f = contadorProfessor, r=0;
    int m = (i + f) / 2;
    for (; f >= i && codP != indiceProfessor[m].codigo_prof; m = (i + f) / 2){
        if (codP > indiceProfessor[m].codigo_prof)
            i = m + 1;
        else
            f = m - 1;
    }
    if (codP == indiceProfessor[m].codigo_prof){
        i = indiceProfessor[m].endProf;
        if(professor[i].statusProf == 1){
            cout<<"\nProfessor Ativo! Deseja realmente excluir o professor?";
            cout<<"\nNome do professor:" <<professor[i].nomeProf;
            cout<<"\n\t0 - Sim  /  1 - Nao";
            cin>>r;
            if(r==0){
                professor[i].statusProf = 0;
                cout<<"\nprofessor excluido com sucesso!"<< endl;


            }
            else{
                cout<<"\nRegistro nao excluido";
            }
        }
    }
    else{
        cout<<"\nRegistro nao existe";
    }
    getch();
}

void leituraExaustivaProfessor (struct professores professor[], struct ind_professores indiceProfessor[], int &contadorProfessor){
    int i=0;
    int j=0;
    for (;j<=contadorProfessor; j++){
        i= indiceProfessor[j].endProf;
        if(professor[i].statusProf == 1){
            cout<<"\nNome: "<<professor[i].nomeProf<<endl;
            cout<<"\nEndereco:"<<professor[i].endereco_prof<<endl;
            printf("\ntelefone:%.0f\n\n", professor[i].telefone);
            cout<<"-------------------------------------------------------"<<endl;
        }
    }
}

void reorganizacaoProfessor (struct professores professor[], struct ind_professores indiceProfessor[],
                             int contadorProfessor, struct professores professorn[], struct ind_professores indiceProfessorn[], int &contadorProfessorn){
    int i=0;
    int j=0;
    contadorProfessorn=0;
    for(; j<contadorProfessor; j++){
        i=indiceProfessor[j].endProf;
        if(professor[i].statusProf == 1){
            professorn[contadorProfessorn].codigo_prof = professor[i].codigo_prof;
            strcpy(professorn[contadorProfessorn].nomeProf, professor[i].nomeProf);
            strcpy(professorn[contadorProfessorn].endereco_prof, professor[i].endereco_prof);
            professorn[contadorProfessorn].telefone = professor[i].telefone;
            professorn[contadorProfessorn].statusProf = professor[i].statusProf;

            indiceProfessorn[contadorProfessorn].codigo_prof = indiceProfessor[j].codigo_prof;
            indiceProfessorn[contadorProfessorn].endProf = contadorProfessorn;
            contadorProfessorn++;
        }
    }
}

void reorganizacaoProfessorn(struct professores professorn[], struct ind_professores indiceProfessorn[], int &contadorProfessorn,
                             struct professores professor[], struct ind_professores indiceProfessor[], int &contadorProfessor){
    contadorProfessor = contadorProfessorn;
    professor = professorn;
    indiceProfessor = indiceProfessorn;
}



//MODALIDADE
void inserir_modalidade(struct modalidades modalidade[], struct ind_modalidades indiceModalidade[], int &contadorModalidade,
                        int codM, struct professores professorn[], int &contadorProfessorn){
    contadorModalidade++;
    int x = 1;
    int achouProfessor;
//	int qtdAluno;
    modalidade[contadorModalidade].codigo_modalidade = codM;
    cout<<"\nInserir nova modalidade... ";
    cout<<"\nCodigo da modalidade: "<<modalidade[contadorModalidade].codigo_modalidade <<endl;
    cout<<"\nDescricao modalidade: ";
    cin>>modalidade[contadorModalidade].descricao;
    modalidade[contadorModalidade].statusModalidade=1;

    x=1;
    while ( x!= 0){
        cout<<"\nDigite o codigo do professor: ";
        cin>>modalidade[contadorModalidade].codigo_prof;
        achouProfessor = verificarProfessor(professorn, modalidade[contadorModalidade].codigo_prof, contadorProfessorn);
        if(achouProfessor != -1){
            x = 0;
        }
        else {
            cout<<"\nNao encontrou professor.Informe um professor valido.";
        }
    }
    cout<<"\nDigite o valor da aula: ";
    cin>>modalidade[contadorModalidade].valor_aula;
    cout<<"\nDigite a quantidade maxima de alunos para fazer a aula: ";
    cin>>modalidade[contadorModalidade].limite_alunos;
    cout<<"\nInforme o total de alunos ja cadastrados na modalidade:"<<endl;
    cin>>modalidade[contadorModalidade].total_alunos;
    if(modalidade[contadorModalidade].limite_alunos > modalidade[contadorModalidade].total_alunos){
        cout<<"\nExistem: "<< modalidade[contadorModalidade].limite_alunos - modalidade[contadorModalidade].total_alunos<<" vagas disponiveis."<<endl;

    }
    else{
        cout<<"N�o existem mais vagas disponiveis para esta modalidade"<<endl;
    }


    int i;
    for(i = contadorModalidade -1; indiceModalidade[i].codigo_modalidade > codM; i --){
        indiceModalidade[i+1].codigo_modalidade = indiceModalidade[i].codigo_modalidade;
        indiceModalidade[i+1].endModalidade = indiceModalidade[i].endModalidade;
    }
    indiceModalidade[i+1].codigo_modalidade = codM;
    indiceModalidade[i+1].endModalidade = contadorModalidade;
    cout<<"\n\nInclusa realizado com sucesso"<< endl;
    getch();
    cout<<"\n\nTecle algo para Retornar..."<<endl;
}

void buscaModalidade(struct modalidades modalidade[], struct ind_modalidades indiceModalidade[],int codM, int contadorModalidade,
                     struct professores professorn[],int contadorProfessorn){
    int saida = 0;
    int i = 0;
    int f = contadorModalidade, r=0;
    int m=(i+f)/2;

    for(; saida != 0 && f >= i && codM != indiceModalidade[m].codigo_modalidade; m = (i + f)/2){
        if(codM > indiceModalidade[m].codigo_modalidade){
            i = m + 1;
        }
        else {
            f = m-1;
        }
    }
    if(codM == indiceModalidade[m].codigo_modalidade){
        cout<<"\n Modalidade encontrada!!!"<<endl;
        i=indiceModalidade[m].endModalidade;
        cout<<"\nDescricao da modalidade: " << modalidade[i].descricao;
    }
    else {
        inserir_modalidade(modalidade, indiceModalidade, contadorModalidade, codM, professorn, contadorProfessorn);
    }
}

void buscaModalidadeExclusao(struct modalidades modalidade[], struct ind_modalidades indiceModalidade[], int &contadorModalidade, int cod){
    int saida = 1;																									//BUSCA EXCLUSAO E EXCLUIR ALUNO
    int i = 0, f = contadorModalidade, r=0;
    int m = (i + f) / 2;
    for (; f >= i && cod != indiceModalidade[m].codigo_modalidade; m = (i + f) / 2){
        if (cod >indiceModalidade[m].codigo_modalidade)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == indiceModalidade[m].codigo_modalidade){
        i = indiceModalidade[m].endModalidade;

        if(modalidade[i].statusModalidade != 0){
            cout<<"Modalidade ativa. Deseja realmente excluir a modalidade?"<<endl;
            cout<<"\nDescriacao da modalidade:" <<modalidade[i].descricao;
            cout<<"\n\t0 - Sim  /  1 - Nao: ";
            cin>>r;
            if(r==0){
                modalidade[i].statusModalidade = 0;
                cout<<"\n Modalidade excluida com sucesso "<< endl;
                contadorModalidade--;
            }
            else{
                cout<<"Registro nao excluido";
            }
        }
        else{
            cout<<"Essa modalidade n existe. ";
        }
    }
}

void leituraExaustivaModalidade(struct modalidades modalidade[], struct ind_modalidades indiceModalidade[], int contadorModalidade,
                                struct professores professorn[], struct ind_professores indiceProfessorn[],int contadorProfessorn){
    contadorModalidade ++;
    int i=0;
    int j=0;
    int achouProfessor;
    int x;
    double valorFaturado;
    int auxiliar;
    for(; j <= contadorModalidade; j++){
        i= indiceModalidade[j].endModalidade;
        if(modalidade[i].statusModalidade == 1){
            cout<<"\nRegistro existente..."<<endl;
            cout<<"\tCodigo da Modalidade: "<<modalidade[i].codigo_modalidade<<endl;
            cout<<"\tNome: "<<modalidade[i].descricao<<endl;
            cout<<"\tCodigo do professor: "<<modalidade[i].codigo_prof;
            auxiliar = modalidade[i].codigo_prof;
            achouProfessor = verificarProfessor(professorn, auxiliar, contadorProfessorn);
            cout<<"\t\n\tQuantidade de alunos: "<<modalidade[i].total_alunos<<endl;
            cout<<"\tLimite de alunos: "<<modalidade[i].limite_alunos<<endl;
            cout<<"\tValor da aula: "<<modalidade[i].valor_aula<<endl<<endl;
            valorFaturado = modalidade[i].valor_aula * modalidade[i].total_alunos;
            cout << "Valor faturado R$" << valorFaturado <<endl;


        }
    }
}

void reorganizaoModalidade(struct modalidades modalidade[], struct ind_modalidades indiceModalidade[], int &contadorModalidade,
                           struct modalidades modalidaden[], struct ind_modalidades indiceModalidaden[],int &contadorModalidaden){
    int i=0;
    int j=0;
    contadorModalidaden = 0;
    for(; j<=contadorModalidade-1; j++){
        i=indiceModalidade[j].endModalidade;
        if(modalidade[i].statusModalidade == 1){
            modalidaden[contadorModalidaden].codigo_modalidade = modalidade[i].codigo_modalidade;
            strcpy(modalidaden[contadorModalidaden].descricao,modalidade[i].descricao);
            modalidaden[contadorModalidaden].codigo_prof = modalidade[i].codigo_prof;
            modalidaden[contadorModalidaden].valor_aula = modalidade[i].valor_aula;
            modalidaden[contadorModalidaden].limite_alunos = modalidade[i].limite_alunos;
            modalidaden[contadorModalidaden].total_alunos = modalidade[i].total_alunos;
            modalidaden[contadorModalidaden].statusModalidade = modalidade[i].statusModalidade;

            indiceModalidaden[contadorModalidaden].codigo_modalidade = indiceModalidade[j].codigo_modalidade;
            indiceModalidaden[contadorModalidaden].endModalidade = contadorModalidaden;
            contadorModalidaden++;
        }
    }
}


void reorganizacaoModalidaden(struct modalidades modalidaden[],struct ind_modalidades indiceModalidaden[], int &contadorModalidaden,
                              struct modalidades modalidade[],struct ind_modalidades indiceModalidade[], int &contadorModalidade){

    contadorModalidade=contadorModalidaden;
    modalidade=modalidaden;
    indiceModalidade=indiceModalidaden;
}


//MATRRICULA
void inserir_matricula(struct modalidades modalidaden[], struct ind_modalidades indiceModalidaden[], int contadorModalidaden,
                       int codMa, struct alunos alunon[],struct ind_alunos indiceAlunon[], int contadorAlunon,
                       struct matriculas matricula[], struct ind_matriculas indiceMatricula[], int &contadorMatricula){
    contadorMatricula++;
    int x = 1;
    float achouAluno;
    int y = 1;
    int achouModalidade;
    float auxcpf;

    matricula[contadorMatricula].codigo_matricula = codMa;
    cout<<"\t\nInserir nova matricula: ";
    cout<<"Codigo da matricula: "<<matricula[contadorMatricula].codigo_matricula;

    x=1;
    while ( x!= 0){
        cout<<"\nDigite o CPF do Aluno a ser matriculado: ";
        cin>>auxcpf;

        matricula[contadorMatricula].cpf = auxcpf;

        achouAluno = verificarAluno(alunon, auxcpf, contadorAlunon, indiceAlunon);
        if(achouAluno != -1){
            x = 0;
        }
        else {
            cout<<"\nNao encontrou o Aluno. Informe um CPF valido.";
        }
    }

    y=1;
    while ( y!= 0){
        cout<<"\nDigite o codigo da Modalidade a ser matriculada: ";
        cin>>matricula[contadorMatricula].codigo_modalidade;

        achouModalidade = verificarModalidade(modalidaden, matricula[contadorMatricula].codigo_modalidade, contadorModalidaden);
        if(achouModalidade != -1){
            y = 0;
        }
        else {
            cout<<"\nNao encontrou a Modalidade. Informe uma Modalidade valida.";
        }
    }

    cout<<"\nDigite a quantidade de aulas: ";
    cin>>matricula[contadorMatricula].quantidade_aula;
    matricula[contadorMatricula].statusMatricula = 1;

    int i;
    for(i = contadorMatricula -1; indiceMatricula[i].codigo_matricula > codMa; i --){
        indiceMatricula[i+1].codigo_matricula = indiceMatricula[i].codigo_matricula;
        indiceMatricula[i+1].endMatricula = indiceMatricula[i].endMatricula;
    }
    indiceMatricula[i+1].codigo_matricula = codMa;
    indiceMatricula[i+1].endMatricula = contadorMatricula;
    cout<<"\n\nInclusao realizado com sucesso"<< endl;
    getch();
    cout<<"\n\nTecle algo para Retornar..."<<endl;

}

void buscaMatricula (struct modalidades modalidaden[], struct ind_modalidades indiceModalidaden[], int &contadorModalidaden,
                     int codMa, struct alunos alunon[],struct ind_alunos indiceAlunon[], int contadorAlunon,
                     struct matriculas matricula[], struct ind_matriculas indiceMatricula[], int &contadorMatricula){
    int saida =1;
    int i = 0, f = contadorMatricula-1, r=0;
    int m= (i + f) / 2;
    for(; saida !=0 && f>= i && codMa != indiceMatricula[m].codigo_matricula; m = (i + f) / 2){
        if (codMa > indiceMatricula[m].codigo_matricula)
            i = m + 1;
        else
            f = m - 1;
    }
    if(codMa == indiceMatricula[m].codigo_matricula){
        cout<<"\n\n Matricula ja realizada - nao pode ser cadastrada novamente";
        i = indiceMatricula[m].endMatricula;
        cout<<"\n Codigo da matricula: "<<matricula[m].codigo_matricula;
        cout<<"\t CPF do aluno matriculado: "<<matricula[m].cpf;
    }
    else {

        inserir_matricula(modalidaden, indiceModalidaden, contadorModalidaden,	codMa,alunon, indiceAlunon,contadorAlunon,
                          matricula, indiceMatricula, contadorMatricula);}
}

void buscaMatriculasExclusao(struct matriculas matricula [], struct ind_matriculas indiceMatricula[], int contadorMatricula, int cod){

    int saida = 1;																									//BUSCA EXCLUSAO E EXCLUIR ALUNO
    int i = 0, f = contadorMatricula, r=0;
    int m = (i + f) / 2;
    for (; f >= i && cod != indiceMatricula[m].codigo_matricula; m = (i + f) / 2){
        if (cod >indiceMatricula[m].codigo_matricula)
            i = m + 1;
        else
            f = m - 1;
    }
    if(cod == indiceMatricula[m].codigo_matricula){
        i=indiceMatricula[m].endMatricula;
        if(matricula[i].statusMatricula == 1){
            cout<<"Matricula Ativa! Deseja realmente excluir matricula";
            cout<<"\n\t0 - Sim  /  1 - Nao";
            cin>>r;
            if(r==0){
                matricula[i].statusMatricula = 0;
                cout<<"\n Matricula excluida com sucesso!"<< endl;


            }
            else{
                cout<<"Registro nao excluido";
            }
        }
    }
}

void leituraExaustivaMatricula(struct matriculas matricula [], struct ind_matriculas indiceMatricula[], int contadorMatricula, struct alunos alunon [],
                               struct ind_alunos indiceAlunon[], int &contadorAlunon){
    int i=0;
    int j=0;
    int achouAluno;
    int x;
    float auxiliar;
    for(; j<=contadorMatricula; j++){
        i= indiceMatricula[j].endMatricula;
        if(matricula[i].statusMatricula == 1){
            cout<<"\nRegistro existente "<<endl;
            cout<<"\n\tCodigo da Matricula "<<matricula[i].codigo_matricula <<endl;
            cout<<"\tCPF do aluno: "<<matricula[i].cpf;
            auxiliar = matricula[i].cpf;
            achouAluno = verificarAluno(alunon, auxiliar, contadorAlunon, indiceAlunon);
            if(achouAluno != -1){
                x = 0;
            }
            else {
                cout<<"\nNao encontrou aluno.Informe um aluno valido.";
            }
        }
    }
}

void reorganizacaoMatricula(struct matriculas matricula[], struct ind_matriculas indiceMatricula[], int contadorMatricula,
                            struct matriculas matriculan[], struct ind_matriculas indiceMatriculan[],int &contadorMatriculan){
    int i=0;
    int j=0;
    contadorMatriculan=0;
    for(; j<contadorMatricula; j++){
        i=indiceMatricula[j].endMatricula;
        if(matricula[i].statusMatricula == 1){
            matriculan[contadorMatriculan].codigo_matricula = matricula[i].codigo_matricula;
            matriculan[contadorMatriculan].cpf = matricula[i].cpf;
            matriculan[contadorMatriculan].codigo_modalidade = matricula[i].codigo_modalidade;
            matriculan[contadorMatriculan].quantidade_aula = matricula[i].quantidade_aula;
            matriculan[contadorMatriculan].statusMatricula = matricula[i].statusMatricula;

            indiceMatriculan[contadorMatriculan].codigo_matricula = indiceMatricula[j].codigo_matricula;
            indiceMatriculan[contadorMatriculan].endMatricula = contadorMatriculan;
            contadorMatriculan++;
        }
    }
}

void reorganizacaoMatriculan(struct matriculas matriculan[],struct ind_matriculas indiceMatriculan[], int &contadorMatriculan,
                             struct matriculas matricula[], struct ind_matriculas indiceMatricula[], int &contadorMatricula){

    contadorMatricula = contadorMatriculan;
    matricula = matriculan;
    indiceMatricula = indiceMatriculan;
}

int main(){
    struct alunos aluno[10] = {
            {11111111111,"mateus","17/02/98",67.5,1.72,1,22.81},
            {33333333333,"emanuel","15/01/03",92,1.83,1,27.47},
            {44444444444,"joao","11/07/03",73,1.75,1,23.83},
            {22222222222,"guilherme","21/01/99",100,1.87,1,28.59}
    };
    struct ind_alunos indiceAluno[10] = {
            {11111111111,0},
            {22222222222,3},
            {33333333333,1},
            {44444444444,2}
    };
    struct professores professor[3] = {
            {8,"Bruno","ruaA",996874565,1},
            {10,"MRGui","ruaB",997256924,1},
            {12,"Talo","ruaC",997882040,1}

    };
    struct ind_professores indiceProfessor[3] = {
            {8,0},
            {10,1},
            {12,2}
    };
    struct modalidades modalidade[3] = {
            {1,"Briga",12,200,5,1,1},
            {2,"musculacao",10,100,10,2,1},
            {3,"Jump",8,120,8,1,1}
    };
    struct ind_modalidades indiceModalidade[3] = {
            {1,0},
            {2,1},
            {3,2}
    };
    struct matriculas matricula[4] = {
            {11,11111111111,2,5,1},
            {12,22222222222,3,2,1},
            {13,33333333333,2,5,1},
            {14,44444444444,1,3,1}
    };
    struct ind_matriculas indiceMatricula[4] = {
            {11,0},
            {12,1},
            {13,2},
            {14,3}
    };

    float cod;
    int codP,codM,codMa;
    int codProfessor;
    int contadorAluno=3;
    int contadorProfessor=2;
    int contadorModalidade=2;
    int contadorMatricula=3;
    int fim = -1;
    int sair;
    int opcao;

    struct alunos alunon[10];
    struct ind_alunos indiceAlunon[10];
    int contadorAlunon;

    struct professores professorn[4];
    struct ind_professores indiceProfessorn[4];
    int contadorProfessorn;

    struct modalidades modalidaden[3];
    struct ind_modalidades indiceModalidaden[3];
    int contadorModalidaden;

    struct matriculas matriculan[4];
    struct ind_matriculas indiceMatriculan[4];
    int contadorMatriculan;


    while( sair==0){
        system("cls");
        cout<<"\t\tOpcoes:\n\n";
        cout<<"\t\t\t1 - Inserir aluno \n\n";
        cout<<"\t\t\t2 - Excluir aluno \n\n";
        cout<<"\t\t\t3 - Leitura de alunos\n\n";
        cout<<"\t\t\t4 - Reorganizar indice Aluno\n\n";
        cout<<"\t\t\t5 - Inserir Professor\n\n";
        cout<<"\t\t\t6 - Excluir Professor\n\n";
        cout<<"\t\t\t7 - Leitura exaustiva Professor\n\n";
        cout<<"\t\t\t8 - Reorganizar indice Professor\n\n";
        cout<<"\t\t\t9 - Inserir Modalidade\n\n";
        cout<<"\t\t\t10 - Excluir Modalidade\n\n";
        cout<<"\t\t\t11 - Leitura exaustiva Modalidade\n\n";
        cout<<"\t\t\t12 - Reorganizar indice Modalidade\n\n";
        cout<<"\t\t\t13 - Inserir Matricula\n\n";
        cout<<"\t\t\t14 - Excluir Matricula\n\n";
        cout<<"\t\t\t15 - Leitura exaustiva Matricula\n\n";
        cout<<"\t\t\t16 - Reorganizar Matricula\n\n";
        cout<<"\t\t\t17 - Encerrar o programa\n\n";
        cout<<"\t\tESCOLHA: ";
        cin>>opcao;


        switch(opcao){

            case 1:{
                system("cls");
                cout << "\n\nInforme o CPF do Aluno a ser INCLUIDO (0 para Encerrar): ";
                cin >> cod;
                if (cod != 0)
                    buscaAluno (indiceAluno, aluno, contadorAluno, cod);
                system("cls");
                cout<<" \n\nTecle algo para retornar ao Menu."<<endl;
                getch();
                break;
            }
            case 2:{
                system("cls");
                cout << "\n\nInforme o cpf do aluno a ser EXCLUIDO (0 para Encerrar): ";
                cin >> cod;
                if (cod != 0){
                    buscaAlunoExclusao (indiceAluno, aluno, contadorAluno, cod);
                }
                cout<<" \n\nTecle algo para retornar ao Menu."<<endl;
                getch();
                break;

            }
            case 3:{
                system("cls");
                leituraExaustivaAluno(aluno, indiceAluno, contadorAluno);
                cout<<" \n\nTecle algo para retornar ao Menu."<<endl;
                getch();
                break;
            }
            case 4:{
                system("cls");
                reorganizacaoAluno(aluno, indiceAluno, contadorAluno, alunon, indiceAlunon, contadorAlunon);

                cout<<"Reorganizando...\n\n Tecle algo para finalizar."<<endl;
                //	reorganizacaoAlunon(alunon, indiceAlunon, contadorAlunon, aluno, indiceAluno, contadorAluno);
                cout<<"\n\nReorganizacao de indice de alunos concluida com sucesso! \n\n Tecle algo para retornar ao menu principal"<<endl;

                getch();
                break;
            }
            case 5:{
                system("cls");
                cout << "\n\nInforme o codigo do professor a ser INCLUIDO (0 para Encerrar): ";
                cin >> codP;
                if (codP != 0)
                    buscaProfessor (indiceProfessor, professor,contadorProfessor, codP);
                getch();
                break;
            }

            case 6:{
                system("cls");
                cout << "\n\nInforme o codigo do PROFESSOR a ser EXCLUIDO (0 para Encerrar): ";
                cin >> codP;
                if (codP != 0)
                    buscaProfessorExclusao(professor,indiceProfessor, contadorProfessor, codP);

                cout<<" \n\nTecle algo para retornar ao Menu."<<endl;
                getch();
                break;
            }

            case 7:{
                system("cls");
                leituraExaustivaProfessor(professor, indiceProfessor, contadorProfessor);
                cout<<" \n\nTecle algo para retornar ao Menu."<<endl;
                getch();
                break;
            }

            case 8:{
                system("cls");
                reorganizacaoProfessor(professor,indiceProfessor,contadorProfessor, professorn,indiceProfessorn,contadorProfessorn);
                //	reorganizacaoProfessorn(professorn, indiceProfessorn,contadorProfessorn,professor, indiceProfessor,contadorProfessor);
                cout<<"Reorganiza��o concluida com sucesso! Tecle para retornar."<<endl;
                getch();
                break;
            }

            case 9:{
                system("cls");
                cout << "\n\nInforme o codigo da Modalidade a ser INCLUIDA (0 para Encerrar): ";
                cin >> codM;
                if (codM != 0)
                    buscaModalidade(modalidade, indiceModalidade, codM, contadorModalidade, professorn, contadorProfessorn);
                getch();
                break;
            }

            case 10:{
                system("cls");
                cout << "\n\nInforme o codigo do MODALIDADE a ser EXCLUIDA (0 para Encerrar): ";
                cin >> codM;
                if (codM != 0){
                    buscaModalidadeExclusao(modalidade, indiceModalidade, contadorModalidade, codM);
                    cout<<" \n\nTecle algo para retornar ao Menu."<<endl;
                    getch();
                    break;
                }
            }

            case 11:{
                system("cls");
                leituraExaustivaModalidade(modalidade, indiceModalidade, contadorModalidade, professorn, indiceProfessorn, contadorProfessorn);
                cout<<" \n\nTecle algo para retornar ao Menu."<<endl;
                getch();
                break;
            }

            case 12:{
                system("cls");
                reorganizaoModalidade(modalidade, indiceModalidade, contadorModalidade, modalidaden, indiceModalidaden, contadorModalidaden);
                //	reorganizacaoModalidaden(modalidaden, indiceModalidaden,contadorModalidaden, modalidade,indiceModalidade, contadorModalidade);
                cout<<"Reorganiza��o concluida com sucesso! Tecle para retornar."<<endl;
                getch();
                break;
            }



            case 13:{
                system("cls");
                cout << "\n\nInforme o codigo da Matricula a ser INCLUIDA (0 para Encerrar): ";
                cin >> codMa;
                if (codMa != 0){

                    buscaMatricula(modalidaden, indiceModalidaden, contadorModalidaden,codMa,alunon, indiceAlunon,contadorAlunon, matricula, indiceMatricula, contadorMatricula);
                }
                getch();
                break;
            }

            case 14:{
                system("cls");
                cout << "\n\nInforme o codigo do MATRICULA a ser EXCLUIDA (0 para Encerrar): ";
                cin >> codMa;
                if (codMa != 0){
                    buscaMatriculasExclusao(matricula, indiceMatricula, contadorMatricula, codMa);
                    cout<<" \n\nTecle algo para retornar ao Menu."<<endl;
                }
                getch();
                break;
            }

            case 15:{
                system("cls");
                leituraExaustivaMatricula(matricula, indiceMatricula, contadorMatricula, alunon, indiceAlunon, contadorAlunon);
                cout<<" \n\nTecle algo para retornar ao Menu."<<endl;
                getch();
                break;
            }

            case 16:{
                system("cls");
                reorganizacaoMatricula(matricula,indiceMatricula, contadorMatricula, matriculan, indiceMatriculan,contadorMatriculan);
                //	reorganizacaoMatriculan(matriculan, indiceMatriculan, contadorMatriculan, matricula, indiceMatricula, contadorMatricula);
                cout<<" \n\nTecle algo para retornar ao Menu."<<endl;
                getch();
                break;
            }


            case 17:{
                system("cls");
                char Encerrar='N';
                cout<<"\n\nDeseja encerrar o programa? (S/N) : ";
                sair=toupper(getche());
                if(Encerrar=='S'){
                    cout<<"\n\nSaindo do programa...";

                }
                getch();
                break;
            }
        }
    }
}

