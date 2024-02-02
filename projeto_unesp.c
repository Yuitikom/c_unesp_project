#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{   
    setlocale(LC_ALL, "Portuguese");

    //todas as habilidades iniciadas com zero.
    int hab[5] = {0,0,0,0,0};
    
    //compHab e suas habilidades.
    int compHab[5] = {20, 60, 80, 40, 10};

    //vetor com nome das habilidades.
    char nomeHab[5][15] = {"Força", "Velocidade", "Resistência", "Inteligência", "Autocura"};

    //esta variável a variávle utilizada para as opções do menu inicial.
    int opcao;

    //variável do número de pontos, começa com 250 máximos pontos.
    int pontos=250;

    //esta variável é a opção usada para selecionar qual habilidade você quer adicionar ou remover pontos.
    int opcao1;

    //esta variável é para voltar ao menu inicial.
    char opcao_volta;

    //quantidade de pontos a tirar ou colocar.
    int n;

    //opção para sair do menu, note que não é a mesma para voltar ao menu, pois entrará em conflito com ela por causa do do-while.
    char opcao_sair_menu;

    do{
        puts("Digite uma opção:\n1-Aumentar habilidade\n2-Reduzir habilidade\n3-Reiniciar\n4-Exibir habilidades\n5-Finalizar.");
        scanf("%d",&opcao);

        //MENU INICIAL
        switch(opcao)
        {
            //AUMENTAR ALGUMA HABILIDADE.
            do{
            case 1:     
                        //quando os pontos acabarem, não deixa o usuário acessar esta opção, pois pode usar de exploit. Note que esta ainda não é a verificação pedida no exercício
                        //apenas uma antiexploit.
                         if(pontos==0)
                        {
                            pontos=0;
                            puts("Não há mais pontos para adicionar.");
                            opcao_volta='s';
                            break;
                        }
                
                        //printando os valores das  habilidades na tela.
                        for(int i=0; i<5; i++)
                        {
                            printf("%s:%d\n",nomeHab[i], hab[i]);
                        }

                        //varrendo a opcao dentro de aumentar habilidade.
                        puts("Escolha uma habilidade para adicionar pontos:\n1-Forca\n2-Velocidade\n3-Resistencia\n4-Inteligencia\n5-Autocura ");
                        scanf("%d", &opcao1);
                        
                        printf("Digite quantos pontos quer aumentar nessa habilidade, pontos iniciais: %d\n", pontos);

                        //escaneando os pontos adicionados.
                        scanf("%d", &n);
                        
                        //anti-exploit: previne o usuário de adicionar mais pontos que ja possui. É um antiexploit para caso o usuário remover pontos e após ganhá-los voltar aqui.
                        //exemplo: pontos = 20, e o usuario adiciona 80.
                        if(n>pontos)
                        {   
                            puts("Não é possível adicionar mais pontos do que você possui, portanto, foi adicionado todos os pontos possuídos.");
                            n=pontos;
                        }

                        //casos escolhidos
                            switch(opcao1)
                            {
                                case 1:
                                    hab[0] += n;
                                    pontos -= n;
                                    break;
                                case 2:
                                    hab[1] += n;
                                    pontos -= n;
                                    break;
                                case 3:
                                    hab[2] += n;
                                    pontos -= n;
                                    break;
                                case 4:
                                    hab[3] += n;
                                    pontos -= n;
                                    break;
                                case 5:
                                    hab[4] += n;
                                    pontos -= n;
                                    break;
                                default:
                                    puts("Digite uma opção válida.");
                                    break;
                    }

                        //condição pedida no exercício. Exemplo se o usuário tem 80 pontos em força e adicionar 30, ele tera adicionara no fim, apenas 20. Note que esse 20 somará aos pontos.
                        if((hab[0]>100)||(hab[1]>100)||(hab[2]>100)||(hab[3]>100)||(hab[3]>100)||(pontos<0))
                        {
                            puts("O valor das habilidades nao podem ser maiores que 100, por isso foi-se reduzida a quantidade de pontos adicionados.");
                            for(int i=n; hab[opcao1-1]>100; i--)
                            {
                                hab[opcao1-1] -= 1;
                                pontos += 1;
                            }
                        }
                
                //condição para voltar ao menu ou não.
                puts("Caso deseje voltar ao menu? s/n");
                scanf(" %c", &opcao_volta);

                //caso o usuário digite qualquer coisa que for além de s ou n.
                if((opcao_volta!='s')&&(opcao_volta!='n'))
                {
                    do
                    {
                        puts("Digite uma opção válida.");
                        scanf(" %c", &opcao_volta);

                    }while((opcao_volta!='s')&&(opcao_volta!='n'));
                }

            }while(opcao_volta=='n');

            //para voltar ao menu inicial.
            if(opcao_volta=='s')
            {
            break;
            }

            //REDUZIR ALGUMA HABILIDADE.
            do{
            case 2: 
                    //anti-exploit: quando o programa inicia as variáveis estão zeradas, então o usuário não pode remover nenhum ponto.
                        if(pontos==250)
                        {   
                            puts("Não há possibilidade de reduzir os pontos, pois todas as habilidades já estão zeradas");
                            opcao_volta='s';
                            break;
                        }

                    //printando os valores das  habilidades na tela.
                    for(int i=0; i<5; i++)
                    {
                        printf("%s:%d\n",nomeHab[i], hab[i]);
                    }
        
                    //varrendo a opção para diminuir habilidade.
                    puts("Escolha uma habilidade para remover pontos:\n1-Forca\n2-Velocidade\n3-Resistencia\n4-Inteligencia\n4-Autocura");
                    scanf("%d", &opcao1);

                    //opções para aumento de habilidade
                    puts("Digite quantos pontos quer retirar nessa habilidade.");

                    //escaneando os pontos adicionados.
                    scanf(" %d", &n);

                    //verificacao pedida no exercicio.
                    //caso o valor retirado for menor que o valor da habilidade, entao sera reduzida a 20 pontos, pontos minimos, e adicionara 20 pontos a quantidade de ponto ja presente.
                    if(((hab[0]<n)||(hab[1]<n)||(hab[2]<n)||(hab[3]<n)||(hab[4]<n)))
                    {
                            puts("A habilidade não pode ter pontos abaixo de 20, portanto, a quantidade de pontos pedida foi reduzida.");
                            hab[opcao1-1] = 20;
                            pontos += 20;
                    }

                    //casos escolhidos.
                      else {
                            switch(opcao1)
                        {
                            case 1:
                                hab[0] -= n;
                                pontos += n;
                                break;
                            case 2:
                                hab[1] -= n;
                                pontos += n;
                                break;
                            case 3:
                                hab[2] -= n;
                                pontos += n;
                                break;
                            case 4:
                                hab[3] -= n;
                                pontos += n;
                                break;
                            case 5:
                                hab[4] -= n;
                                pontos += n;
                                break;
                            default:
                                puts("Digite uma opção válida.");
                                 break;
                        }
                    }

                //condição para voltar ao menu ou não.
                puts("Deseja voltar ao menu? s/n");
                scanf(" %c", &opcao_volta);

                //caso o usuário digite qualquer coisa que for além de s ou n.
                if((opcao_volta!='s')&&(opcao_volta!='n'))
                {
                    do
                    {
                        puts("Digite uma opcao valida.");
                        scanf(" %c", &opcao_volta);

                    }while((opcao_volta!='s')&&(opcao_volta!='n'));
                }

            }while(opcao_volta=='n');

            if(opcao_volta=='s')
            {
            break;
            }
            
            //REINICIAR AS HABILIDADES.
            case 3:
                //reiniciando as habilidades.
                for(int i=0; i<5;i++)
                {
                hab[i]=0;
                }
                //reiniciandos os pontos ao máximo e voltando para o menu inicial.
                pontos = 250;
                puts("Todas as habilidades foram zeradas.");
                opcao_volta='s';

                break;

            //MOSTRAR OS VALORES DAS HABILIDADES E OS PONTOS RESTANTES.
            case 4:
                //printando os valores do vetor Hab.
                for(int i=0; i<5;i++)
                {
                printf("%s:%d\n", nomeHab[i], hab[i]);
                }

                //printando os pontos restantes e voltando ao menu inicial.
                printf("Pontos restantes: %d\n", pontos);
                opcao_volta='s';

                break;

            //SAIR DO MENU.
            case 5:
                puts("Deseja  sair do menu e começar o combate? s/n");
                scanf(" %c", &opcao_sair_menu);

                //caso o usuário digite qualquer coisa que for além de s ou n.
                if((opcao_sair_menu!='s')&&(opcao_sair_menu!='n'))
                {
                    do
                    {
                        puts("Digite uma opção válida.");
                        scanf(" %c", &opcao_sair_menu);

                    }while((opcao_sair_menu!='s')&&(opcao_sair_menu!='n'));
                }

                //caso os pontos nao estiverem zerados ou alguma componente do vetor está zerada, irá voltar para o menu de opções.
                if((opcao_sair_menu=='s' && pontos!=0) || (opcao_sair_menu=='s' && hab[0]==0) || (opcao_sair_menu=="s" && hab[1]==0) || (opcao_sair_menu=='s' && hab[2]==0)||(opcao_sair_menu=='s' && hab[4]==0))
                {
                    puts("Os pontos ainda não estão zerados ou alguma habilidade está zerada.");
                    opcao_volta='s';
                    break;

                }
                //caso os pontos estiverem zerados
                else if ((opcao_sair_menu=='s') && (pontos==0))
                {
                    opcao_volta='n';
                    break;
                }

                break;

            //CASO O USUÁRIO DIGITE UMA OUTRA OPÇÃO.
            default:

                puts("Digite uma opção válida. ");
                opcao_volta='s';
                break;

        }

    }while(opcao_volta=='s');

    //Sistema de combate.

    //Pontuação do player e do computador.
    int pontos_combate_hab=0;
    int pontos_combate_habComp=0;

    if(opcao_sair_menu=='s')
    {   
        //TURNO 1

        puts("Turno 1");
        sleep(2);

        //Se a sua força e velocidade for maior que a resistência de habComp e sua velocidade for maior que a dele, você causa dano.
        if((hab[0]>compHab[2])&&(hab[1]>compHab[1]))
        {   
            printf("Você causou %d dano de força a resistência do habComp", hab[0]);
            //dano e soma com a autocura.
            compHab[0] -= hab[2] + compHab[4];
            pontos_combate_hab += 50;
        }else
        {
            puts("Você não causou dano em habComp.");
            pontos_combate_hab += 20;
        }
        sleep(2);
        //TURNO 1
        
        //TURNO 2
        puts("Turno 2");
        sleep(2);

        //Se a forca de habComp e sua velocidade for maior que a sua resistencia e velocidade ele te causara dano.
        if((hab[0]>compHab[2])&&(compHab[1]>hab[1]))
        {   
            printf("habComp causou %d dano de força a sua resistência.", hab[0]);
            //dano e soma com a autocura.
            hab[0] -= compHab[2] + hab[4];
            pontos_combate_habComp += 50;
        }else 
        {
            puts("habComp não te causou dano.");
            pontos_combate_habComp += 20;
        }
        sleep(2);

        //TURNO 3
        puts("Turno 3");
        sleep(2);

        if((hab[3]>compHab[3]))
        {
             puts("Você dará mais cinco porcento de ataque em habComp.");
             compHab[0] -= (hab[2] + (5/100*hab[2])) + compHab[4];
             pontos_combate_hab += 70;
             
        }
        else
        {
            puts("Você não deu dano adicional a habComp");
            hab[0] -= compHab[2] + hab[4];
            pontos_combate_hab += 30;
        } 

        sleep(2);

        //TURNO 4
        puts("Turno 4");
        sleep(2);

        if((compHab[3]>hab[3]))
        {
             puts("habComp te deu mais cinco porcento de ataque.");
             hab[0] -= (compHab[2] + (5/100*hab[2])) + hab[4];
             pontos_combate_habComp += 70;
             
        }
        else
        {
            puts("habComp não te deu dano adicional.");
            hab[0] -= compHab[2] + hab[4];
            pontos_combate_habComp += 30;
        } 



        //RESULTADOS.
        if(pontos_combate_hab > pontos_combate_habComp)
        {
            puts("Parabéns, você venceu.");
            return 0;
        }
        else
        {
            puts("Oh não! Você perdeu.");
            return 0;
        }

    }

    return 0;
}
