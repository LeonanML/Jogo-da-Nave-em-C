#include<stdio.h>
#include<stdlib.h>

using namespace System;

#define ESTADO_JOGO_MENU_PRINCIPAL 0
#define ESTADO_JOGO_GAMEPLAY 1
#define ESTADO_JOGO_GAMEPLAY 2

int main(){
	//O que sera o jogador
	const Char JOGADOR_GRAFICO = (Char)9608;
	const Char METEORITO = (Char)9608;
	
	//posição inicial, setar sempre no eixo 'x' e 'y'
	int jogador_x = 40;
	int jogador_y = 20;

	//Meteoritos
	int meteorito_x = 10;
	int meteorito_y = 10;
	bool meteorito_ext = true;


	int meteorito2_x = 24;
	int meteorito2_y = 6;
	bool meteorito2_ext = true;

	//BOT
	bool bot_ext = true;
	bool bot_left = true;
	bool bot_right = false;
	int bot_x = 40;
	int bot_y = 3;
	int mov_bot_x = bot_x;
	int mov_bot_y = bot_y;
	


	//Meteorito Randomico  NÃO FUNFOU
	int rand_x, rand_y;
	bool metrand_ext = true;
	rand_x = 25 + (rand() % 46);
	rand_y = 25 + (rand() % 46);
	/*
		Para fazer com que um número ‘x’ receba um valor entre 1 e 10, fazemos:
		x = 1 + ( rand() % 10 )
	*/



	//posição do projétil
	int projetil_x = 0;
	int projetil_y = 0;

	//variavel bool para saber se o projetil foi ou não disparado
	bool projetil_mov = false;

	//...
	int estadoDoJogo;

	//tecla a ser precionada
	ConsoleKeyInfo tecla;

	//Inicio do Game Loop
	for (;;){
		
		switch (estadoDoJogo){//Inicio do switch
		case ESTADO_JOGO_MENU_PRINCIPAL:
				
			Console::BackgroundColor = ConsoleColor::Black;
		
			//Mesma coisa que o system('cls')
			Console::Clear();
			
			//Tela de Apresentação
			Console::SetCursorPosition(12, 5);
			Console::WriteLine(" _______  _       _________ _______  _        _______ ");
			Console::SetCursorPosition(12, 6);
			Console::WriteLine("(  ___  )( \\      \\__   __/(  ____ \\( (    /|(  ____ \\");
			Console::SetCursorPosition(12, 7);
			Console::WriteLine("| (   ) || (         ) (   | (    \\/|  \\  ( || (    \\/");
			Console::SetCursorPosition(12, 8);
			Console::WriteLine("| (___) || |         | |   | (__    |   \\ | || (_____ ");
			Console::SetCursorPosition(12, 9);
			Console::WriteLine("|  ___  || |         | |   |  __)   | (\\ \\) |(_____  )");
			Console::SetCursorPosition(12, 10);
			Console::WriteLine("| (   ) || |         | |   | (      | | \\   |      ) |");
			Console::SetCursorPosition(12, 11);
			Console::WriteLine("| )   ( || (____/\\___) (___| (____/\\| )  \\  |/\\____) |");
			Console::SetCursorPosition(12, 12);
			Console::WriteLine("|/     \\|(_______/\\_______/(_______/|/    )_)\\_______)");


			Console::SetCursorPosition(8,15);
			Console::Write("Saudações Piloto, pressione <ENTER> para ajudar a salvar a terra...");

			Console::SetCursorPosition(21, 17);
			Console::Write("Direcionais movimenram e SpaceBar atira!!");

			Console::SetCursorPosition(23,25);
			Console::Write("Programado por Leonan 'cYber' Müller");

			//NOTA IMPORTANTE PRA CARALHO: 'SetCursorPosition(x,y);' temq ser usado a partir de um plano cartesiano
			//com os eixos x = linha e y = coluna  **se tu esquecer isso te sento a vara fdp**

			//Verificação para saber a tecla precionada
			if (Console::KeyAvailable){
				
				tecla = Console::ReadKey(true); //pega tecla
				if (tecla.Key == ConsoleKey::Enter){ //se for enter
					estadoDoJogo = ESTADO_JOGO_GAMEPLAY; //então altera o estado do jogo para gameplay 
				}
			}
			break;

		case ESTADO_JOGO_GAMEPLAY:
			Console::BackgroundColor = ConsoleColor::Black;
			Console::Clear();

			if (projetil_mov){
				Console::SetCursorPosition(projetil_x, projetil_y);
				Console::Write("x");
				
			}

			if (Console::KeyAvailable){
				tecla = Console::ReadKey(true);

				if (jogador_x == 3){//Colisão Esquerda
					jogador_x++;

				}
				else if (jogador_x == 76){//Colisão Direita
					jogador_x--;
				}
				else if (jogador_y == 2){//Colisão Cima
					jogador_y++;
				}
				else if (jogador_y == 23){//Colisão Baixo
					jogador_y--;
				}

				else if (tecla.Key == ConsoleKey::LeftArrow){//Esquerda
					jogador_x--;
					//Tentei fazer a fuckin colisão mas n consegui
				}
				else if (tecla.Key == ConsoleKey::RightArrow){//Direita
					jogador_x++;
				}
				else if (tecla.Key == ConsoleKey::UpArrow){//Cima
					jogador_y--;
				
				}
				else if (tecla.Key == ConsoleKey::DownArrow){//Baixo
					jogador_y++;
				
				}
				else if (tecla.Key == ConsoleKey::Spacebar){//Tiro
					projetil_mov = true;
					projetil_x = jogador_x;
					projetil_y = jogador_y - 1;
				}
				
			
			}

			if (projetil_mov){
				projetil_y--;
				if (projetil_y == 0){
					projetil_mov = false;
				}
			}

			if (meteorito_ext == true){
				Console::ForegroundColor = ConsoleColor::DarkGreen;
				Console::SetCursorPosition(meteorito_x, meteorito_y);
				Console::Write(METEORITO);
			}
			if ((projetil_x == 10) && (projetil_y == 10)){
				meteorito_ext = false;
				projetil_mov = false;
			}



			if (meteorito2_ext == true){
				Console::ForegroundColor = ConsoleColor::DarkGreen;
				Console::SetCursorPosition(meteorito2_x, meteorito2_y);
				Console::Write(METEORITO);
			}
			if ((projetil_x == 24) && (projetil_y == 6)){
				meteorito2_ext = false;
				projetil_mov = false;
			}


			if (bot_ext == true){
				Console::ForegroundColor = ConsoleColor::Red;
				Console::SetCursorPosition(mov_bot_x, mov_bot_y);
				Console::Write(METEORITO);
				if (bot_left == true){
					mov_bot_x++;
					if (mov_bot_x == 73){
						mov_bot_y++;
						bot_left = false;
						bot_right = true;
					}
				}
				if (bot_right == true){
					mov_bot_x--;
					if (mov_bot_x == 4){
						bot_right = false;
						bot_left = true;
					}
				}
				if ((mov_bot_y == jogador_y) && (mov_bot_x == jogador_x)){
					goto fim;
				}
				if (mov_bot_y > 20){
					goto fim;
				}
			}


			//Colisão com o BOT
			if ((projetil_x == mov_bot_x) && (projetil_y == mov_bot_y)){
				bot_ext = false;
				projetil_mov = false;
			}








			/* TENTEI MAS NÃO DEU =[
			if (metrand_ext == true){
				Console::ForegroundColor = ConsoleColor::Red;
				Console::SetCursorPosition(rand_x, rand_y);
				Console::Write(METEORITO);
			
			}
			if ((projetil_x == rand_x) && (projetil_y == rand_y)){
				metrand_ext = false;
				projetil_mov = false;
			
			}
			*/





			Console::ForegroundColor = ConsoleColor::Gray;
			Console::SetCursorPosition(jogador_x, jogador_y);
			Console::Write(JOGADOR_GRAFICO);

			break;




		
		}//Fim do switch




		Threading::Thread::Sleep(40);
	}//Fim do Game Loop
	
	fim:
	Console::SetCursorPosition(3, 5);
	Console::WriteLine(" _______  _______  _______  _______    _______           _______  _______ ");
	Console::SetCursorPosition(3, 6);
	Console::WriteLine("(  ____ \\(  ___  )(       )(  ____ \\  (  ___  )|\\     /|(  ____ \\(  ____ )");
	Console::SetCursorPosition(3, 7);
	Console::WriteLine("| (    \\/| (   ) || () () || (    \\/  | (   ) || )   ( || (    \\/| (    )|");
	Console::SetCursorPosition(3, 8);
	Console::WriteLine("| |      | (___) || || || || (__      | |   | || |   | || (__    | (____)|");
	Console::SetCursorPosition(3, 9);
	Console::WriteLine("| | ____ |  ___  || |(_)| ||  __)     | |   | |( (   ) )|  __)   |     __)");
	Console::SetCursorPosition(3, 10);
	Console::WriteLine("| | \\_  )| (   ) || |   | || (        | |   | | \\ \\_/ / | (      | (\\ (   ");
	Console::SetCursorPosition(3, 11);
	Console::WriteLine("| (___) || )   ( || )   ( || (____/\\  | (___) |  \\   /  | (____/\\| ) \\ \\__");
	Console::SetCursorPosition(3, 12);
	Console::WriteLine("(_______)|/     \\||/     \\|(_______/  (_______)   \\_/   (_______/|/   \\__/");

	printf("\n\n\n");
	system("pause");
	return 0;
}