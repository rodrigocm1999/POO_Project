# POO_Project
    Ano = 6 turnos
    Todas as produções acontecem 1 vez por turno

## Territorios
    Nome, Resistencia, Produção de produtos, Produção de ouro, Pontos de vitória
    
	Território Inicial: resistencia 9, produtos e ouro 1
	Continente: 1 Ponto de vitória, tipos:
		1. Planície - resistência 5, 1º ano produz 1 produtos e ouro, 2º ano 2 produtos e ouro
		2. Montanha - resistência 6, 2 primeiros turnos : produz 0, depois produz 1 produtos
		3. Fortaleza - resistência 8
		4. Mina - resistência 5, produz 1 ouro nos 3 primeiros turnos, produz 2 na segunda metade do ano
		5. Duna - resistência 4, produz 1 produtos
		6. Castelo - resistência 7, produz 1 ouro, produz 3 produtos nos 2 primeiros turnos do ano
	Ilha - 2 Ponto de vitória, tipos:
		1. Refúgio dos Piratas - resistência 9, produz 1 ouro
		2. Pescaria - resistência 9, primeiro ano produz 2 produtos, segundo ano produz 4 produtos
		
## Tecnologias
    **Apenas 1 de cada**
	1. Drones militares:  limite máximo da força militar passa para 5
		Custa 3 ouro
	2. Mísseis teleguiados:  necessária para conquistar ilhas (necessário ter 5 territórios para conquistar ilhas)
		Custa 4 ouro
	3. Defesas territoriais:  acrescenta 1 unidade à resistência dos territórios invadidos, pode ter mais que 1
		Custa 4 ouro
	4. Bolsa de valores: torna possíveis as trocas entre produtos e ouro
		Custa 2 ouro
	5. Banco Central: armazenar até 5 de produtos e 5 de ouro
		Custa 3 ouro

## Fases
	1. Conquistar/Passar - escolhe o territorio a conquistar e conquista
	2. Recolha de produtos e ouro - recebe o produzido e se tiver "Bolsa de valores" pode fazer 1 troca
	3. Compra de unidades militares e tecnologias:
	    1. Aumentar Força Militar - apenas uma por turno
	        Custa 1 unidade de produtos e 1 ouro
        2. Adquirir Tecnologia - apenas uma por turno
	4. Occorência de um evento:
	    **Apenas um por turno de forma random**
		1. Recurso Abandonado - caso ja haja o maximo o recurso é disperdiçado (nao faz nada)
		    1.1 - primeiro ano adiciona 1 unidade de produtos
		    1.2 - segundo ano adiciona 1 de ouro
		2. Invasão - Ultimo territorio conquistado volta para o mundo (fator sorte 1-6)
		    Sorte + forca de invasao (1 ano = 2; 2 ano = 3) se maior a resistencia do territorio entao ja nao é adicionado
		    Caso contrario e exista Defesas Territoriais é add 1 nivel de resistencia do territorio que sofre a invasao
		    Se o Territorio Inicial for invadido o jogo acaba em derrota
		3. Aliança Diplomatica - Adiciona 1 unidade de Força Militar caso seja menor que max
		4. Sem evento

## Fim do jogo
    1. Somatorio dos pontos de cada territorio conquistado
    2. Ponto adicional por cada tecnologia adquirida
    3. Bonus Cientifico - 5 tecnologias adquiridas = +1 ponto
    4. Imperador Supremo - 3 pontos se todos os territorios fizerem parte do Imperio
    
## Comandos
    1. carrega - done
    2. cria - done
    3. conquista - almost done
    4. passa - passa o turno sem fazer nada
    5. maisouro - trocar 2 produtos por 1 ouro
    6. maisprod - trocar 2 ouro por 1 produto
    7. maismilitar - trocar 1 ouro e 1 produto por 1 força militar
    8. adquire <tipo> - adquirir o tipo de tecnologio com o respetivo preço
    9. lista <nome> - kinda done
    10. anvanca - passa para a proxima fase 
    11. grava <nome> - grava o jogo em memoria
    12. ativa <nome> - recupera um jogo da memoria e passa a ser o atual
    13. apaga <nome> - apaga o jogo da memoria
    14. toma <qual> <nome> - adquirir territorio ou tecnologia sem seguir as regras **apenas para debug**
    15. modifica <ouro|prod> N - modifica a quantide de prod ou ouro **apenas para debug**
    16. fevento <nome-evento> - força um evento **apenas para debug**
    
    