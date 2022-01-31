#include <vector>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include "ActionDeck.h"
#include "House.h"
#include "Pet.h"
#include "Career.h"
#include "CollegeCareer.h"
#include "Bank.h"
#include "Spinner.h"
#include "ActionSpace.h"
#include "PetSpace.h"
#include "Player1Graduation.h"
#include "Player1PayDay.h"
#include "ActionSpace2.h"
#include "PetSpace2.h"
#include "Player2Graduation.h"
#include "Player2PayDay.h"

using namespace std;

int main()
{
	string userInput1, userInput2, userResponse, userDecision1, userDecision2, userPath1, userPath2; // All used for loop activation, conditional statements, and interaction with the games questions.
	string player1, player2; // Name characters.

	int userPlayer = 1; // Keeps track of current player.
	int player1Storage = 0; // Tracks players money.
	int player2Storage = 0;
	int player1Salary = 0; // Tracks players salary based on their job.
	int player2Salary = 0;
	int player1Position = 0; // Tracks players position on "board."
	int player2Position = 0;
	int userInput3; // int type of other userInputs.
	int userInput4;
	int userInput5;
	int num; // Used for salary algorithm.
	char userResponseSub2; // For short "character" involved user responses.

	// 43-155--instructions and title.
	cout << "                                     Objectives and Instructions" << endl;
	cout << "                                     ---------------------------" << endl;
	cout << endl;
	cout << "Game objective:" << endl;
	cout << "'Hit the road for a roller-coaster life of adventure, family, unexpected surprises, and pets!" << endl;
	cout << "The player with the most money at the end of the game wins!'" << endl;
	cout << endl;
	cout << "Instructions:" << endl;
	cout << "1.) Give each player: 1 car and matching Spin to Win token." << endl;
	cout << "1 pink or blue peg." << endl;
	cout << "1 pet peg." << endl;
	cout << "200k" << endl;
	cout << "2.) Split the cards into five decks, and put them next to the board." << endl;
	cout << "(House cards, Action cards, Career cards, College Career cards, Pet cards)" << endl;
	cout << "3.) Choose a banker." << endl;
	cout << "The banker gives you your salary when you pass over or land on a Payday space." << endl;
	cout << "If anyone runs out of money, the banker gives them a bank loan." << endl;
	cout << "4.) Each player, choose your path." << endl;
	cout << "Choose College?:" << endl;
	cout << "You'll be more likely to get a better paying job. Pay the bank 100k in tuition fees immediately." << endl;
	cout << "Choose career?:" << endl;
	cout << "You'll get paid sooner. Take the top two Career cards from the deck, choose your favorite, and place it face up in front of you." << endl;
	cout << "That's your job! Return the other card to the bottom of the deck." << endl;
	cout << "5.) Pop your pegs in your car, and tell everyone your pet's name! Now you're ready to start!" << endl;
	cout << endl;
	cout << "Play (instructions)" << endl;
	cout << "How to win:" << endl;
	cout << "Move your car from start to retirement and experience all sorts of unexpected adventures. Once everyone's retired, the wealthiest player wins." << endl;
	cout << "Who goes first:" << endl;
	cout << "The youngest playeer goes first, and play moves to the left." << endl;
	cout << "On your turn:" << endl;
	cout << "1.) Spin the spinner, and move that many spaces along the path. On your first turn, start on the career path you choose." << endl;
	cout << "Payday:" << endl;
	cout << "If you pass a payday space, collect the salary on your career or college career card from the bank." << endl;
	cout << "2.) Your turn ends, and the next player may spin!" << endl;
	cout << "The Board Spaces: (instruction)" << endl;
	cout << "Payday spaces:" << endl;
	cout << "If you PASS a payday space , collect the salary on your career or college career card from the bank." << endl;
	cout << "If you LAND on a payday space, collect your salary AND take an additional 100k bonus!" << endl;
	cout << "Action spaces:" << endl;
	cout << "When you land here, ta,e the top Action card from the deck, read it aloud, and do what it says. Keep the card until the end of the game. It's worth money!" << endl;
	cout << "Spin to Win spaces:" << endl;
	cout << "1.) When you land here, all players choose a number on the spin to win wheel and place their token on that number." << endl;
	cout << "You get to put a second token (the silver one) on a second number." << endl;
	cout << "2.) Spin the spinner until a number with a token on it comes up. That player wins 200k!" << endl;
	cout << "Baby spaces:" << endl;
	cout << "When you land here, you've had a baby! Add as many pegs to your car as the space tells you." << endl;
	cout << "House spaces:" << endl;
	cout << "When you land here, you may choose to buy a house, sell a house, or do nothing." << endl;
	cout << "'To buy a house':" << endl;
	cout << "Take the top two house cards from the deck. Choose your favorite, and pay the bank the purchase price. Return the other card to the deck." << endl;
	cout << "You may own more than one house!" << endl;
	cout << "'To sell a house':" << endl;
	cout << "Spin the spinner. Then look at the center of the spinner to see if your spin is red or black. Collect the sale price for that color, as listed on the house card, from the bank. Return the card to the deck." << endl;
	cout << "Pet spaces:" << endl;
	cout << "When you land here, draw the top pet card from the deck. Read it aloud, and do what it says. Keep the card until the the end of the game. It's woth money." << endl;
	cout << endl;
	cout << "Stop! Spaces (instructions):" << endl;
	cout << "When you come to a STOP! space, stop your token there even if you have moves left. Each STOP! space is different." << endl;
	cout << "Graduation STOP!: Take the top two College Career cards from the deck." << endl;
	cout << "Choose your favorite, and place it faceup in front of you." << endl;
	cout << "That's your job! Return the other card to the deck. Spin again, and move" << endl;
	cout << "Get Married STOP!: It's your wedding day! Pop a peg in your car--that's your new husband or wife!" << endl;
	cout << "Spin for cash gifts from everyone. Red? Collect 50k. Blac? Collect 100k. Spin again, and move." << endl;
	cout << "Night School STOP!: (choose your path)" << endl;
	cout << "Night School:" << endl;
	cout << "If you want to change your career, pay the bank 100k to go to Night School." << endl;
	cout << "Take the top College Career card. If you want to keep it, place it faceup in front of you, and return your other Career card to the deck." << endl;
	cout << "Otherwise, keep your current Career card. Spin again, and move." << endl;
	cout << "You love your current job!:" << endl;
	cout << "Keep your current Career card. Spin again, and continue on the life path." << endl;
	cout << "Family SOTP!: (choose your path)" << endl;
	cout << "Family path:" << endl;
	cout << "Spin again, and head this way to have kids!" << endl;
	cout << "You have other plans:" << endl;
	cout << "Spin again, and continue on the life path." << endl;
	cout << "Baby STOP!:" << endl;
	cout << "Spin the spinner to see ho many babies you've had. Pop the pegs into your car. Spin again, and move." << endl;
	cout << "Risky STOP!: (choose your path)" << endl;
	cout << "Risky road:" << endl;
	cout << "Spin again, and head this way to win--or lose--big money." << endl;
	cout << "Safe route:" << endl;
	cout << "Spin again, and head this way to take the safe route. No big risks for you!" << endl;
	cout << endl;
	cout << "Out of money? Get a bank loan! (instruction):" << endl;
	cout << "If you don't have enough money to pay a debt or buy something, you must take out a bank loan." << endl;
	cout << "the banker gives you cash from the bank plus one bank loan certificate for every 50k you need to borrow." << endl;
	cout << "Pay the loan off at any time by returning each certiicate to the bank along with 60k in cash." << endl;
	cout << "Any loans you have left at the end of the game will be taken off your fial cash count." << endl;
	cout << endl;
	cout << "Retirement:" << endl;
	cout << "When you reach the retirement space, choose whether to go to the millionaire mansion or countryside acres." << endl;
	cout << "Park your car, kick back, and wait for everyone else to retire. Collect your retirement bonus from the bank." << endl;
	cout << "Bonus' in order:" << endl;
	cout << "1st to retire: collect 400k" << endl;
	cout << "2nd to retire: collect 300k" << endl;
	cout << "3rd to retire: collect 200k" << endl;
	cout << "4th to retire: collect 100k" << endl;
	cout << "The end of the Game:" << endl;
	cout << "Once everyone has retired, everyone pays their debts and adds up their wealth by doing the following:" << endl;
	cout << "1.) Sell your houses: Spin to find out how much they're worth, and collect cash from the bank." << endl;
	cout << "2.) Collect 100k for each action card you have." << endl;
	cout << "3.) Collect 100k for each pet card you have." << endl;
	cout << "4.) Colelct 50k for each baby you have." << endl;
	cout << "5.) Pay the bank 60k for each loan you have." << endl;
	cout << "6.) Count your cash! If you have the most, you win!" << endl;
	cout << endl;
	cout << endl;
	cout << "                                            The Game of LIFE" << endl;
	cout << "                                    -Tanner Wagner & Jaden Gonzales" << endl;
	cout << "                                     ------------------------------" << endl;
	cout << endl;

	// Start of main game.
	while (true)
	{
		cout << "How many people are playing? ('two' min and 'four' max)" << endl;
		cin >> userInput1;

		if (userInput1 == "two" || "Two")
		{
			cout << "Name player 1: "; // Initializes and stores player's names.
			cin >> player1;
			cout << "Name player 2: ";
			cin >> player2;
			cout << endl;
			cout << "Enter 'play' to move on to the main game." << endl;
			cin >> userResponse;
			cout << endl;

			while (userInput2 == "play" || "Play")
			{
				cout << "                                   REMINDER" << endl;
				cout << "                                   --------" << endl;
				cout << player1 << " and " << player2 << ", " << "you both start out with 1 pet peg and 200k in cash." << endl;
				cout << "Hold on to your pet peg until the end of the game in order to get some extra cash." << endl;
				cout << endl;

				player1Storage = 200000; // Simulated bank account.
				player2Storage = 200000;

				cout << player1 << " current balance: " << player1Storage << endl;
				cout << player2 << " current balance: " << player2Storage << endl;
				cout << endl;
				cout << player1 << " would you like to go the 'college' path or the 'life' path ?" << endl;
				cin >> userPath1;

				if (userPath1 == "college" || "College" || "life" || "Life")
				{
					userDecision1 = userPath1; // Path recognition.
					cout << player1 << " you chose the " << userDecision1 << " path." << endl;
					cout << endl;
					cout << player2 << " would you like to go the 'college' path or the 'life' path?" << endl;
					cin >> userPath2;

					if (userPath2 == "college" || "College" || "life" || "Life")
					{
						userDecision2 = userPath2;
						cout << player2 << " you chose the " << userDecision2 << " path." << endl;
					}
				}

				if (userPlayer == 1) // Player 1.
				{
					cout << endl;
					cout << player1 << " enter 'spin' to see how many spaces you move." << endl;
					srand(time(0)); // Initializing seed to zero helps with random simulation.
					cin >> userResponse;

					if (userResponse == "spin" || "Spin")
					{
						Spinner SpinTheWheelOfFortune; // Call spinner function.
						SpinTheWheelOfFortune.randomSpin();

						cout << "What did you roll?" << endl;
						cin >> userInput3;

						// Switch statement takes user's input and initializes their position on the board to that input.
						// 10 cases becaue 10 spots on spinner.
						switch (userInput3)
						{
						case 1:
							player1Position += 1;
							break;
						case 2:
							player1Position += 2;
							break;
						case 3:
							player1Position += 3;
							break;
						case 4:
							player1Position += 4;
							break;
						case 5:
							player1Position += 5;
							break;
						case 6:
							player1Position += 6;
							break;
						case 7:
							player1Position += 7;
							break;
						case 8:
							player1Position += 8;
							break;
						case 9:
							player1Position += 9;
							break;
						case 10:
							player1Position += 10;
							break;
						}
					}

					cout << "Spaces 1-5 are action spaces." << endl; // User direction.
					cout << "Space 6 is a pet space." << endl;
					cout << "Spaces 7-10 are action spaces." << endl;
					cout << endl;
					cout << "If you landed on an action space, enter 'action'." << endl;
					cout << "If you landed on a pet space, enter 'pet'." << endl;
					cin >> userResponse;

					if (userResponse == "action" || "Action")
					{
						cout << "You landed on an action space." << endl;
						cout << "Enter 'draw' to pick up a random action card." << endl;
						cin >> userResponse;
						cout << endl;

						if (userResponse == "draw" || "Draw")
						{
							Action randAction; // Call card function.
							randAction.ActionCards();

							cout << endl; // More user instruction; commands for the computer.
							cout << "INITIAL INSTRUCTION" << endl;
							cout << "-------------------" << endl;
							cout << "What did your card tell you to do?" << endl;
							cout << endl;
							cout << "'pay another player', 'pay the bank', 'highest spinner gets paid', 'collect from the bank', 'collect from another player' " << endl;
							cout << "'spin a certain color', 'fired', 'spin a certain number to get paid', '10k x some ammount'." << endl;
							cout << "Here are a list of commands that you should use after you have pulled an action card:" << endl;
							cout << "'pay'--to pay another player." << endl;
							cout << "'give'--to pay the bank." << endl;
							cout << "'highest'--highest spinner gets payed." << endl;
							cout << "'collect'--collect from bank" << endl;
							cout << "'player'--collect from player" << endl;
							cout << "'color'--spin a color" << endl;
							cout << "'fired'" << endl;
							cout << "'number'--spin a number" << endl;
							cout << "'ten'--10 x some ammount of money." << endl;
							cout << endl;
							cout << "So . . . what did your card tell you to do?" << endl;

							cin >> userResponse;

							if (userResponse == "pay") // Conditional statements each represent a cards functin.
							{
								cout << "How much do you owe the other player?" << endl;
								cin >> userInput3;

								player1Storage -= userInput3; // Updating users bank account with input value.
								player2Storage += userInput3;

								cout << player1 << " current balance: " << player1Storage << endl;
								cout << player1 << " current board position: " << player1Position << endl;
								cout << player2 << " current balance: " << player2Storage << endl;

								userPlayer = 2; // End of move; switched to player 2.
							}
							else if (userResponse == "give")
							{
								cout << "How much do you owe the bank?" << endl;
								cin >> userInput3;

								player1Storage -= userInput3;

								cout << player1 << " current balance: " << player1Storage << endl;
								cout << player1 << " current board position: " << player1Position << endl;

								userPlayer = 2;
							}
							else if (userResponse == "highest")
							{
								cout << player1 << " please 'spin' the wheel for both players." << endl;
								srand(time(0));
								cin >> userResponse;

								if (userResponse == "spin" || "Spin")
								{
									for (int i = 0; i < 2; ++i)
									{
										Spinner SpinTheWheelOfFortune; // Call spinner functin.
										SpinTheWheelOfFortune.randomSpin();
									}

									cout << player1 << ", which turn had the highest roll?" << endl;
									cin >> userInput4;

									if (userInput4 == 1) // If player 1 rolled the highest, add money to their account, otherwise, add money to player 2's account.
									{
										cout << "How much does " << player2 << " owe you?" << endl;
										cin >> userInput5;

										player1Storage += userInput5;
										player2Storage -= userInput5;

										cout << player1 << " current balance: " << player1Storage << endl;
										cout << player1 << " current board position: " << player1Position << endl;
										cout << endl;
										cout << player2 << " current balance: " << player2Storage << endl;

										userPlayer = 2;
									}
									else if (userInput4 == 2)
									{
										cout << "How much does " << player1 << " owe you?" << endl;
										cin >> userInput5;

										player1Storage -= userInput5;
										player2Storage += userInput5;

										cout << player1 << " current balance: " << player1Storage << endl;
										cout << player1 << " current board position: " << player1Position << endl;
										cout << endl;
										cout << player2 << " current balance: " << player2Storage << endl;

										userPlayer = 2;
									}
								}
							}
							else if (userResponse == "collect")
							{
								cout << "How much does the bank owe you?" << endl;
								cin >> userInput5;

								player1Storage += userInput5;

								cout << player1 << " current balance: " << player1Storage << endl;
								cout << player1 << " current board position: " << player1Position << endl;

								userPlayer = 2;
							}
							else if (userResponse == "player")
							{
								cout << "How much does " << player2 << " owe you?" << endl;
								cin >> userInput5;

								player1Storage += userInput5;
								player2Storage -= userInput5;

								cout << player1 << " current balance: " << player1Storage << endl;
								cout << player1 << " current board position: " << player1Position << endl;
								cout << player2 << " current balance: " << player2Storage << endl;

								userPlayer = 2;
							}
							else if (userResponse == "color") // Pays a player based off of what color they rolled. Color's are set with spinners numbers.
							{
								cout << player1 << " please 'spin' the wheel." << endl;
								srand(time(0));
								cin >> userResponse;

								if (userResponse == "spin" || "Spin")
								{
									for (int i = 0; i < 1; ++i)
									{
										Spinner SpinTheWheelOfFortune; // Function call.
										SpinTheWheelOfFortune.randomSpin();
									}

									cout << "What number did you spin?" << endl;
									cin >> userInput5;

									if (userInput5 == 1 || userInput5 == 3 || userInput5 == 5 || userInput5 == 7 || userInput5 == 9) // Conditional check for spinners color number correlation.
									{
										const int RED_VAL = 40000;

										cout << "You landed a red space." << endl;
										cout << "You get an automatic 40k added to your bank account." << endl;

										player1Storage += RED_VAL; // Updating user's bank account with respect to the constant RED_VAL.

										cout << player1 << " current balance: " << player1Storage << endl;
										cout << player1 << " current board position: " << player1Position << endl;

										userPlayer = 2;
									}
									else if (userInput5 == 2 || userInput5 == 4 || userInput5 == 6 || userInput5 == 8 || userInput5 == 10)
									{
										const int BLACK_VAL = 50000;

										cout << "You landed a black space." << endl;
										cout << "You get an automatic 50k added to your bank account." << endl;

										player1Storage += BLACK_VAL;

										cout << player1 << " current balance: " << player1Storage << endl;
										cout << player1 << " current board position: " << player1Position << endl;

										userPlayer = 2;
									}
								}
							}
							else if (userResponse == "fired")
							{
								cout << "You were fired from your job." << endl;
								cout << "If you do not have a job yet, this does not apply to you." << endl;
								cout << "Please press 'c' to ignore." << endl;
								cout << "However, if this does apply to you--press 'v' to continue." << endl;
								cin >> userResponseSub2;

								if (userResponseSub2 == 'c')
								{
									userPlayer = 2; // If the player does not have a job yet, they can press 'c' and the turn goes to player 2.
								}
								else if (userResponseSub2 == 'v')
								{
									cout << "Please 'draw' another career card." << endl;
									cin >> userResponse;

									if (userResponse == "draw")
									{
										Career randCareer; // Another card function.
										randCareer.CareerCards();
									}

									cout << "This is your new career." << endl;
									cout << "What is your new salary?" << endl;
									cin >> userInput5;

									player1Salary = userInput5; // Intializing player salary with user input which is in turn determined by their job card.

									cout << player1 << " your salary is: " << player1Salary << endl;
									cout << player1 << " current board position: " << player1Position << endl;

									userPlayer = 2;
								}
							}
							else if (userResponse == "number") // Player owes other money based off of what number they roll.
							{
								cout << "Does your card want all players to spin or just yourself?" << endl;
								cin >> userResponse;

								if (userResponse == "me")
								{
									cout << player1 << " please 'spin' the wheel." << endl;
									srand(time(0));
									cin >> userResponse;

									if (userResponse == "spin" || "Spin")
									{
										for (int i = 0; i < 1; ++i)
										{
											Spinner SpinTheWheelOfFortune;
											SpinTheWheelOfFortune.randomSpin();
										}

										cout << "What number did you spin?" << endl;
										cin >> userInput5;

										if (userInput5 >= 1 && userInput5 <= 5)
										{
											player1Storage += 50000;

											cout << player1 << " current balance: " << player1Storage << endl;
											cout << player1 << " current board position: " << player1Position << endl;

											userPlayer = 2;
										}
										else if (userInput5 >= 5 && userInput5 <= 10)
										{
											player1Storage += 100000;

											cout << player1 << " current balance: " << player1Storage << endl;
											cout << player1 << " current board position: " << player1Position << endl;

											userPlayer = 2;
										}
									}
								}
								else if (userResponse == "all")
								{
									cout << player1 << " please 'spin' the wheel." << endl;
									srand(time(0));
									cin >> userResponse;

									if (userResponse == "spin" || "Spin")
									{
										for (int i = 0; i < 1; ++i)
										{
											Spinner SpinTheWheelOfFortune;
											SpinTheWheelOfFortune.randomSpin();
										}

										cout << "What number did you spin?" << endl;
										cin >> userInput5;

										if (userInput5 >= 1 && userInput5 <= 5)
										{
											player1Storage += 50000;

											cout << player1 << " current balance: " << player1Storage << endl;
											cout << player1 << " current board position: " << player1Position << endl;

											// Notice, player is not switched to 2 because of nested function.
										}
										else if (userInput5 >= 5 && userInput5 <= 10)
										{
											player1Storage += 100000;

											cout << player1 << " current balance: " << player1Storage << endl;
											cout << player1 << " current board position: " << player1Position << endl;
										}

										cout << player2 << " please 'spin' the wheel." << endl;
										srand(time(0));
										cin >> userResponse;

										if (userResponse == "spin" || "Spin")
										{
											for (int i = 0; i < 1; ++i)
											{
												Spinner SpinTheWheelOfFortune;
												SpinTheWheelOfFortune.randomSpin();
											}

											cout << "What number did you spin?" << endl;
											cin >> userInput5;

											if (userInput5 >= 1 && userInput5 <= 5)
											{
												player2Storage += 50000;

												cout << player2 << " current balance: " << player2Storage << endl;

												userPlayer = 2;
											}

											else if (userInput5 >= 5 && userInput5 <= 10)
											{
												player2Storage += 100000;

												cout << player2 << " current balance: " << player2Storage << endl;

												userPlayer = 2;
											}
										}
									}
								}
							}
							else if (userResponse == "ten")
							{
								cout << player1 << ", 'spin' the wheel." << endl;
								srand(time(0));
								cin >> userResponse;

								if (userResponse == "spin" || "Spin")
								{
									for (int i = 0; i < 1; ++i)
									{
										Spinner SpinTheWheelOfFortune;
										SpinTheWheelOfFortune.randomSpin();
									}

									cout << "What did you spin?" << endl;
									cin >> userInput5;

									switch (userInput5) // Switch statement is used to cleanup player's bank account update.
									{
									case 1:
										num = 10000 * userInput5;

										player1Storage += num;

										cout << player1 << " current balance: " << player1Storage << endl;
										cout << player1 << " current board position: " << player1Position << endl;

										userPlayer = 2;
										break;
									case 2:
										num = 10000 * userInput5;

										player1Storage += num;

										cout << player1 << " current balance: " << player1Storage << endl;
										cout << player1 << " current board position: " << player1Position << endl;

										userPlayer = 2;
										break;
									case 3:
										num = 10000 * userInput5;

										player1Storage += num;

										cout << player1 << " current balance: " << player1Storage << endl;
										cout << player1 << " current board position: " << player1Position << endl;

										userPlayer = 2;
										break;
									case 4:
										num = 10000 * userInput5;

										player1Storage += num;

										cout << player1 << " current balance: " << player1Storage << endl;
										cout << player1 << " current board position: " << player1Position << endl;

										userPlayer = 2;
										break;
									case 5:
										num = 10000 * userInput5;

										player1Storage += num;

										cout << player1 << " current balance: " << player1Storage << endl;
										cout << player1 << " current board position: " << player1Position << endl;

										userPlayer = 2;
										break;
									case 6:
										num = 10000 * userInput5;

										player1Storage += num;

										cout << player1 << " current balance: " << player1Storage << endl;
										cout << player1 << " current board position: " << player1Position << endl;

										userPlayer = 2;
										break;
									case 7:
										num = 10000 * userInput5;

										player1Storage += num;

										cout << player1 << " current balance: " << player1Storage << endl;
										cout << player1 << " current board position: " << player1Position << endl;

										userPlayer = 2;
										break;
									case 8:
										num = 10000 * userInput5;

										player1Storage += num;

										cout << player1 << " current balance: " << player1Storage << endl;
										cout << player1 << " current board position: " << player1Position << endl;

										userPlayer = 2;
										break;
									case 9:
										num = 10000 * userInput5;

										player1Storage += num;

										cout << player1 << " current balance: " << player1Storage << endl;
										cout << player1 << " current board position: " << player1Position << endl;

										userPlayer = 2;
										break;
									case 10:
										num = 10000 * userInput5;

										player1Storage += num;

										cout << player1 << " current balance: " << player1Storage << endl;
										cout << player1 << " current board position: " << player1Position << endl;

										userPlayer = 2;
										break;
									}
								}
							}
						}
					}
					else if (userResponse == "pet" || "Pet")
					{
						cout << "You landed on a pet space." << endl;
						cout << "Enter 'draw' to pick up a random pet card." << endl;
						cin >> userResponse;
						cout << endl;

						if (userResponse == "draw" || "Draw")
						{
							Pet randPet; // Random pet cards function.
							randPet.PetCards();

							cout << endl;
							cout << "INITIAL INSTRUCTION" << endl;
							cout << "-------------------" << endl;
							cout << "What did your card tell you to do?" << endl;
							cout << endl;
							cout << "'pay another player', 'pay the bank', 'collect from the bank', 'collect from another player' " << endl;
							cout << ",'earn some ammount of money for each pet you have', 'give some ammount of money to the bank for each pet you have'." << endl;
							cout << "Here are a list of commands that you should use after you have pulled an action card:" << endl;
							cout << "'pay'--to pay another player." << endl;
							cout << "'give'--to pay the bank." << endl;
							cout << "'collect'--collect from bank" << endl;
							cout << "'player'--collect from player" << endl;
							cout << "'number'--spin a number" << endl;
							cout << "'earn'--earn money based off how many pets you have." << endl;
							cout << "'lose'--pay the bank based off how many pets you have." << endl;
							cout << endl;
							cout << "So . . . what did your card tell you to do?" << endl;
							cin >> userResponse;

							if (userResponse == "pay")
							{
								cout << "How much do you owe the other player?" << endl;
								cin >> userInput3;

								player1Storage -= userInput3;
								player2Storage += userInput3;

								cout << player1 << " current balance: " << player1Storage << endl;
								cout << player1 << " current board position: " << player1Position << endl;
								cout << player2 << " current balance: " << player2Storage << endl;

								userPlayer = 2;
							}
							else if (userResponse == "give")
							{
								cout << "How much do you owe the bank?" << endl;
								cin >> userInput3;

								player1Storage -= userInput3;

								cout << player1 << " current balance: " << player1Storage << endl;
								cout << player1 << " current board position: " << player1Position << endl;

								userPlayer = 2;
							}
							else if (userResponse == "collect")
							{
								cout << "How much does the bank owe you?" << endl;
								cin >> userInput5;

								player1Storage += userInput5;

								cout << player1 << " current balance: " << player1Storage << endl;
								cout << player1 << " current board position: " << player1Position << endl;

								userPlayer = 2;
							}
							else if (userResponse == "player")
							{
								cout << "How much does " << player2 << " owe you?" << endl;
								cin >> userInput5;

								player1Storage += userInput5;
								player2Storage -= userInput5;

								cout << player1 << " current balance: " << player1Storage << endl;
								cout << player1 << " current board position: " << player1Position << endl;
								cout << player2 << " current balance: " << player2Storage << endl;

								userPlayer = 2;
							}
							else if (userResponse == "highest")
							{
								cout << player1 << " please 'spin' the wheel for both players." << endl;
								srand(time(0));
								cin >> userResponse;

								if (userResponse == "spin" || "Spin")
								{
									for (int i = 0; i < 2; ++i)
									{
										Spinner SpinTheWheelOfFortune;
										SpinTheWheelOfFortune.randomSpin();
									}

									cout << player1 << ", which turn had the highest roll?" << endl;
									cin >> userInput4;

									if (userInput4 == 1)
									{
										cout << "How much does " << player2 << " owe you?" << endl;
										cin >> userInput5;

										player1Storage += userInput5;
										player2Storage -= userInput5;

										cout << player1 << " current balance: " << player1Storage << endl;
										cout << player1 << " current board position: " << player1Position << endl;
										cout << player2 << " current balance: " << player2Storage << endl;

										userPlayer = 2;
									}
									else if (userInput4 == 2)
									{
										cout << "How much does " << player1 << " owe you?" << endl;
										cin >> userInput5;

										player1Storage -= userInput5;
										player2Storage += userInput5;

										cout << player1 << " current balance: " << player1Storage << endl;
										cout << player1 << " current board position: " << player1Position << endl;
										cout << player2 << " current balance: " << player2Storage << endl;

										userPlayer = 2;
									}
								}
							}
							else if (userResponse == "earn")
							{
								cout << "How many pets do you have?" << endl;
								cin >> userInput5;

								switch (userInput5) // Switch statement gives player money based off of pet card.
								{
								case 0:
									player1Storage += 0;

									cout << player1 << " current balance: " << player1Storage << endl;
									cout << player1 << " current board position: " << player1Position << endl;

									userPlayer = 2;
									break;
								case 1:
									player1Storage += 10000;

									cout << player1 << " current balance: " << player1Storage << endl;
									cout << player1 << " current board position: " << player1Position << endl;

									userPlayer = 2;
									break;
								case 2:
									player1Storage += 20000;

									cout << player1 << " current balance: " << player1Storage << endl;
									cout << player1 << " current board position: " << player1Position << endl;

									userPlayer = 2;
									break;
								case 3:
									player1Storage += 30000;

									cout << player1 << " current balance: " << player1Storage << endl;
									cout << player1 << " current board position: " << player1Position << endl;

									userPlayer = 2;
									break;
								case 4:
									player1Storage += 40000;

									cout << player1 << " current balance: " << player1Storage << endl;
									cout << player1 << " current board position: " << player1Position << endl;

									userPlayer = 2;
									break;
								case 5:
									player1Storage += 50000;

									cout << player1 << " current balance: " << player1Storage << endl;
									cout << player1 << " current board position: " << player1Position << endl;

									userPlayer = 2;
									break;
								}
							}
							else if (userResponse == "lose") // Opposite.
							{
								cout << "How many pets do you have?" << endl;
								cin >> userInput5;

								switch (userInput5)
								{
								case 0:
									player1Storage -= 0;

									cout << player1 << " current balance: " << player1Storage << endl;
									cout << player1 << " current board position: " << player1Position << endl;

									userPlayer = 2;
									break;
								case 1:
									player1Storage -= 10000;

									cout << player1 << " current balance: " << player1Storage << endl;
									cout << player1 << " current board position: " << player1Position << endl;

									userPlayer = 2;
									break;
								case 2:
									player1Storage -= 20000;

									cout << player1 << " current balance: " << player1Storage << endl;
									cout << player1 << " current board position: " << player1Position << endl;

									userPlayer = 2;
									break;
								case 3:
									player1Storage -= 30000;

									cout << player1 << " current balance: " << player1Storage << endl;
									cout << player1 << " current board position: " << player1Position << endl;

									userPlayer = 2;
									break;
								case 4:
									player1Storage -= 40000;

									cout << player1 << " current balance: " << player1Storage << endl;
									cout << player1 << " current board position: " << player1Position << endl;

									userPlayer = 2;
									break;
								case 5:
									player1Storage -= 50000;

									cout << player1 << " current balance: " << player1Storage << endl;
									cout << player1 << " current board position: " << player1Position << endl;

									userPlayer = 2;
									break;
								}
							}
						}
					}
				}
				if (userPlayer == 2) // Player 2's turn.
				{
					// Comments won't be used as much because everything is virtually the same as it is for player 1.

					cout << player2 << " current balance: " << player2Storage << endl; // Re-display of player's bank account's.
					cout << player1 << " current balance: " << player1Storage << endl;
					cout << endl;

					cout << player2 << " enter 'spin' to see how many spaces you move." << endl;
					srand(time(0));
					cin >> userResponse;

					if (userResponse == "spin" || "Spin")
					{
						Spinner SpinTheWheelOfFortune;
						SpinTheWheelOfFortune.randomSpin();

						cout << "What did you roll?" << endl;
						cin >> userInput3;

						switch (userInput3) // Updates position.
						{
						case 1:
							player2Position += 1;
							break;
						case 2:
							player2Position += 2;
							break;
						case 3:
							player2Position += 3;
							break;
						case 4:
							player2Position += 4;
							break;
						case 5:
							player2Position += 5;
							break;
						case 6:
							player2Position += 6;
							break;
						case 7:
							player2Position += 7;
							break;
						case 8:
							player2Position += 8;
							break;
						case 9:
							player2Position += 9;
							break;
						case 10:
							player2Position += 10;
							break;
						}

						cout << "Spaces 1-5 are action spaces." << endl;
						cout << "Space 6 is a pet space." << endl;
						cout << "Spaces 7-10 are action spaces." << endl;
						cout << endl;
						cout << "If you landed on an action space, enter 'action'." << endl;
						cout << "If you landed on a pet space, enter 'pet'." << endl;
						cin >> userResponse;

						if (userResponse == "action" || "Action")
						{
							cout << "You landed on an action space." << endl;
							cout << "Enter 'draw' to pick up a random action card." << endl;
							cin >> userResponse;
							cout << endl;

							if (userResponse == "draw" || "Draw")
							{
								Action randAction;
								randAction.ActionCards();

								cout << endl;
								cout << "INITIAL INSTRUCTION" << endl;
								cout << "-------------------" << endl;
								cout << "What did your card tell you to do?" << endl;
								cout << endl;
								cout << "'pay another player', 'pay the bank', 'highest spinner gets paid', 'collect from the bank', 'collect from another player' " << endl;
								cout << "'spin a certain color', 'fired', 'spin a certain number to get paid', '10k x some ammount'." << endl;
								cout << "Here are a list of commands that you should use after you have pulled an action card:" << endl;
								cout << "'pay'--to pay another player." << endl;
								cout << "'give'--to pay the bank." << endl;
								cout << "'highest'--highest spinner gets payed." << endl;
								cout << "'collect'--collect from bank" << endl;
								cout << "'player'--collect from player" << endl;
								cout << "'color'--spin a color" << endl;
								cout << "'fired'" << endl;
								cout << "'number'--spin a number" << endl;
								cout << "'ten'--10 x some ammount of money." << endl;
								cout << endl;
								cout << "So . . . what did your card tell you to do?" << endl;
								cin >> userResponse;

								if (userResponse == "pay")
								{
									cout << "How much do you owe the other player?" << endl;
									cin >> userInput3;

									player2Storage -= userInput3;
									player1Storage += userInput3;

									cout << player2 << " current balance: " << player2Storage << endl;
									cout << player2 << " current board position: " << player2Position << endl;
									cout << player1 << " current balance: " << player1Storage << endl;

									userPlayer = 1;
								}
								else if (userResponse == "give")
								{
									cout << "How much do you owe the bank?" << endl;
									cin >> userInput3;

									player2Storage -= userInput3;

									cout << player2 << " current balance: " << player2Storage << endl;
									cout << player2 << " current board position: " << player2Position << endl;

									userPlayer = 1;
								}
								else if (userResponse == "highest")
								{
									cout << player2 << " please 'spin' the wheel for both players." << endl;
									srand(time(0));
									cin >> userResponse;

									if (userResponse == "spin" || "Spin")
									{
										for (int i = 0; i < 2; ++i)
										{
											Spinner SpinTheWheelOfFortune;
											SpinTheWheelOfFortune.randomSpin();
										}

										cout << player2 << ", which turn had the highest roll?" << endl;
										cin >> userInput4;

										if (userInput4 == 1)
										{
											cout << "How much does " << player1 << " owe you?" << endl;
											cin >> userInput5;

											player2Storage += userInput5;
											player1Storage -= userInput5;

											cout << player2 << " current balance: " << player2Storage << endl;
											cout << player2 << " current board position: " << player2Position << endl;
											cout << player1 << " current balance: " << player1Storage << endl;

											userPlayer = 1;
										}
										else if (userInput4 == 2)
										{
											cout << "How much does " << player2 << " owe you?" << endl;
											cin >> userInput5;

											player2Storage -= userInput5;
											player1Storage += userInput5;

											cout << player2 << " current balance: " << player2Storage << endl;
											cout << player2 << " current board position: " << player2Position << endl;
											cout << player1 << " current balance: " << player1Storage << endl;

											userPlayer = 1;
										}
									}
								}
								else if (userResponse == "collect")
								{
									cout << "How much does the bank owe you?" << endl;
									cin >> userInput5;

									player2Storage += userInput5;

									cout << player2 << " current balance: " << player2Storage << endl;
									cout << player2 << " current board position: " << player2Position << endl;

									userPlayer = 1;
								}
								else if (userResponse == "player")
								{
									cout << "How much does " << player1 << " owe you?" << endl;
									cin >> userInput5;

									player2Storage += userInput5;
									player1Storage -= userInput5;

									cout << player2 << " current balance: " << player2Storage << endl;
									cout << player2 << " current board position: " << player2Position << endl;
									cout << player1 << " current balance: " << player1Storage << endl;

									userPlayer = 1;
								}
								else if (userResponse == "color")
								{
									cout << player2 << " please 'spin' the wheel." << endl;
									srand(time(0));
									cin >> userResponse;

									if (userResponse == "spin" || "Spin")
									{
										for (int i = 0; i < 1; ++i)
										{
											Spinner SpinTheWheelOfFortune;
											SpinTheWheelOfFortune.randomSpin();
										}

										cout << "What number did you spin?" << endl;
										cin >> userInput5;

										if (userInput5 == 1 || userInput5 == 3 || userInput5 == 5 || userInput5 == 7 || userInput5 == 9)
										{
											const int RED_VAL = 40000;

											cout << "You landed a red space." << endl;
											cout << "You get an automatic 40k added to your bank account." << endl;

											player2Storage += RED_VAL;

											cout << player2 << " current balance: " << player2Storage << endl;
											cout << player2 << " current board position: " << player2Position << endl;

											userPlayer = 1;
										}
										else if (userInput5 == 2 || userInput5 == 4 || userInput5 == 6 || userInput5 == 8 || userInput5 == 10)
										{
											const int BLACK_VAL = 50000;

											cout << "You landed a black space." << endl;
											cout << "You get an automatic 50k added to your bank account." << endl;

											player2Storage += BLACK_VAL;

											cout << player2 << " current balance: " << player2Storage << endl;
											cout << player2 << " current board position: " << player2Position << endl;

											userPlayer = 1;
										}
									}
								}
								else if (userResponse == "fired")
								{
									cout << "You were fired from your job." << endl;
									cout << "If you do not have a job yet, this does not apply to you." << endl;
									cout << "Please press 'c' to ignore." << endl;
									cout << "However, if this does apply to you--press 'v' to continue." << endl;
									cin >> userResponseSub2;

									if (userResponseSub2 == 'c')
									{
										userPlayer = 1; // Skips turn and switches to player 1.
									}
									else if (userResponseSub2 == 'v')
									{
										cout << "Please 'draw' another career card." << endl;
										cin >> userResponse;

										if (userResponse == "draw")
										{
											Career randCareer;
											randCareer.CareerCards();
										}

										cout << "This is your new career." << endl;
										cout << "What is your new salary?" << endl;
										cin >> userInput5;

										player2Salary = userInput5;

										cout << player2 << " your salary is: " << player2Salary << endl;
										cout << player2 << " current board position: " << player2Position << endl;

										userPlayer = 1;
									}
								}
								else if (userResponse == "number")
								{
									cout << "Does your card want all players to spin or just yourself?" << endl;
									cin >> userResponse;

									if (userResponse == "me")
									{
										cout << player2 << " please 'spin' the wheel." << endl;
										srand(time(0));
										cin >> userResponse;

										if (userResponse == "spin" || "Spin")
										{
											for (int i = 0; i < 1; ++i)
											{
												Spinner SpinTheWheelOfFortune;
												SpinTheWheelOfFortune.randomSpin();
											}

											cout << "What number did you spin?" << endl;
											cin >> userInput5;

											if (userInput5 >= 1 && userInput5 <= 5)
											{
												player2Storage += 50000;

												cout << player2 << " current balance: " << player2Storage << endl;
												cout << player2 << " current board position: " << player2Position << endl;

												userPlayer = 1;
											}
											else if (userInput5 >= 5 && userInput5 <= 10)
											{
												player2Storage += 100000;

												cout << player2 << " current balance: " << player2Storage << endl;
												cout << player2 << " current board position: " << player2Position << endl;

												userPlayer = 1;
											}
										}
									}
									else if (userResponse == "all")
									{
										cout << player2 << " please 'spin' the wheel." << endl;
										srand(time(0));
										cin >> userResponse;

										if (userResponse == "spin" || "Spin")
										{
											for (int i = 0; i < 1; ++i)
											{
												Spinner SpinTheWheelOfFortune;
												SpinTheWheelOfFortune.randomSpin();
											}

											cout << "What number did you spin?" << endl;
											cin >> userInput5;

											if (userInput5 >= 1 && userInput5 <= 5)
											{
												player2Storage += 50000;

												cout << player2 << " current balance: " << player2Storage << endl;
												cout << player2 << " current board position: " << player2Position << endl;
											}
											else if (userInput5 >= 5 && userInput5 <= 10)
											{
												player2Storage += 100000;

												cout << player2 << " current balance: " << player2Storage << endl;
												cout << player2 << " current board position: " << player2Position << endl;
											}

											cout << player1 << " please 'spin' the wheel." << endl;
											srand(time(0));
											cin >> userResponse;

											if (userResponse == "spin" || "Spin")
											{
												for (int i = 0; i < 1; ++i)
												{
													Spinner SpinTheWheelOfFortune;
													SpinTheWheelOfFortune.randomSpin();
												}

												cout << "What number did you spin?" << endl;
												cin >> userInput5;

												if (userInput5 >= 1 && userInput5 <= 5)
												{
													player1Storage += 50000;

													cout << player1 << " current balance: " << player1Storage << endl;

													userPlayer = 1;
												}
												else if (userInput5 >= 5 && userInput5 <= 10)
												{
													player1Storage += 100000;

													cout << player1 << " current balance: " << player1Storage << endl;

													userPlayer = 1;
												}
											}
										}
									}
								}
								else if (userResponse == "ten")
								{
									cout << player2 << ", 'spin' the wheel." << endl;
									srand(time(0));
									cin >> userResponse;

									if (userResponse == "spin" || "Spin")
									{
										for (int i = 0; i < 1; ++i)
										{
											Spinner SpinTheWheelOfFortune;
											SpinTheWheelOfFortune.randomSpin();
										}

										cout << "What did you spin?" << endl;
										cin >> userInput5;

										switch (userInput5) // Pay day bonus.
										{
										case 1:
											num = 10000 * userInput5;

											player2Storage += num;

											cout << player2 << " current balance: " << player2Storage << endl;
											cout << player2 << " current board position: " << player2Position << endl;

											userPlayer = 1;
											break;
										case 2:
											num = 10000 * userInput5;

											player2Storage += num;

											cout << player2 << " current balance: " << player2Storage << endl;
											cout << player2 << " current board position: " << player2Position << endl;

											userPlayer = 1;
											break;
										case 3:
											num = 10000 * userInput5;

											player2Storage += num;

											cout << player2 << " current balance: " << player2Storage << endl;
											cout << player2 << " current board position: " << player2Position << endl;

											userPlayer = 1;
											break;
										case 4:
											num = 10000 * userInput5;

											player2Storage += num;

											cout << player2 << " current balance: " << player2Storage << endl;
											cout << player2 << " current board position: " << player2Position << endl;

											userPlayer = 1;
											break;
										case 5:
											num = 10000 * userInput5;

											player2Storage += num;

											cout << player2 << " current balance: " << player2Storage << endl;
											cout << player2 << " current board position: " << player2Position << endl;

											userPlayer = 1;
											break;
										case 6:
											num = 10000 * userInput5;

											player2Storage += num;

											cout << player2 << " current balance: " << player2Storage << endl;
											cout << player2 << " current board position: " << player2Position << endl;

											userPlayer = 1;
											break;
										case 7:
											num = 10000 * userInput5;

											player2Storage += num;

											cout << player2 << " current balance: " << player2Storage << endl;
											cout << player2 << " current board position: " << player2Position << endl;

											userPlayer = 1;
											break;
										case 8:
											num = 10000 * userInput5;

											player2Storage += num;

											cout << player2 << " current balance: " << player2Storage << endl;
											cout << player2 << " current board position: " << player2Position << endl;

											userPlayer = 1;
											break;
										case 9:
											num = 10000 * userInput5;

											player2Storage += num;

											cout << player2 << " current balance: " << player2Storage << endl;
											cout << player2 << " current board position: " << player2Position << endl;

											userPlayer = 1;
											break;
										case 10:
											num = 10000 * userInput5;

											player2Storage += num;

											cout << player2 << " current balance: " << player2Storage << endl;
											cout << player2 << " current board position: " << player2Position << endl;

											userPlayer = 1;
											break;
										}
									}
								}
							}
						}
						else if (userResponse == "pet" || "Pet")
						{
							cout << "You landed on a pet space." << endl;
							cout << "Enter 'draw' to pick up a random pet card." << endl;
							cin >> userResponse;
							cout << endl;

							if (userResponse == "draw" || "Draw")
							{
								Pet randPet;
								randPet.PetCards();

								cout << endl;
								cout << "INITIAL INSTRUCTION" << endl;
								cout << "-------------------" << endl;
								cout << "What did your card tell you to do?" << endl;
								cout << endl;
								cout << "'pay another player', 'pay the bank', 'collect from the bank', 'collect from another player' " << endl;
								cout << ",'earn some ammount of money for each pet you have', 'give some ammount of money to the bank for each pet you have'." << endl;
								cout << "Here are a list of commands that you should use after you have pulled an action card:" << endl;
								cout << "'pay'--to pay another player." << endl;
								cout << "'give'--to pay the bank." << endl;
								cout << "'collect'--collect from bank" << endl;
								cout << "'player'--collect from player" << endl;
								cout << "'number'--spin a number" << endl;
								cout << "'earn'--earn money based off how many pets you have." << endl;
								cout << "'lose'--pay the bank based off how many pets you have." << endl;
								cout << endl;
								cout << "So . . . what did your card tell you to do?" << endl;
								cin >> userResponse;

								if (userResponse == "pay")
								{
									cout << "How much do you owe the other player?" << endl;
									cin >> userInput3;

									player2Storage -= userInput3;
									player1Storage += userInput3;

									cout << player2 << " current balance: " << player2Storage << endl;
									cout << player2 << " current board position: " << player2Position << endl;
									cout << player1 << " current balance: " << player1Storage << endl;

									userPlayer = 1;
								}
								else if (userResponse == "give")
								{
									cout << "How much do you owe the bank?" << endl;
									cin >> userInput3;

									player2Storage -= userInput3;

									cout << player2 << " current balance: " << player2Storage << endl;
									cout << player2 << " current board position: " << player2Position << endl;

									userPlayer = 1;
								}
								else if (userResponse == "collect")
								{
									cout << "How much does the bank owe you?" << endl;
									cin >> userInput5;

									player2Storage += userInput5;

									cout << player2 << " current balance: " << player2Storage << endl;
									cout << player2 << " current board position: " << player2Position << endl;

									userPlayer = 1;
								}
								else if (userResponse == "player")
								{
									cout << "How much does " << player2 << " owe you?" << endl;
									cin >> userInput5;

									player2Storage += userInput5;
									player1Storage -= userInput5;

									cout << player2 << " current balance: " << player2Storage << endl;
									cout << player2 << " current board position: " << player2Position << endl;
									cout << player1 << " current balance: " << player1Storage << endl;

									userPlayer = 1;
								}
								else if (userResponse == "highest")
								{
									cout << player2 << " please 'spin' the wheel for both players." << endl;
									srand(time(0));
									cin >> userResponse;

									if (userResponse == "spin" || "Spin")
									{
										for (int i = 0; i < 2; ++i)
										{
											Spinner SpinTheWheelOfFortune;
											SpinTheWheelOfFortune.randomSpin();
										}

										cout << player2 << ", which turn had the highest roll?" << endl;
										cin >> userInput4;

										if (userInput4 == 1)
										{
											cout << "How much does " << player1 << " owe you?" << endl;
											cin >> userInput5;

											player2Storage += userInput5;
											player1Storage -= userInput5;

											cout << player2 << " current balance: " << player2Storage << endl;
											cout << player2 << " current board position: " << player2Position << endl;
											cout << player1 << " current balance: " << player1Storage << endl;

											userPlayer = 1;
										}
										else if (userInput4 == 2)
										{
											cout << "How much does " << player1 << " owe you?" << endl;
											cin >> userInput5;

											player2Storage -= userInput5;
											player1Storage += userInput5;

											cout << player2 << " current balance: " << player2Storage << endl;
											cout << player2 << " current board position: " << player2Position << endl;
											cout << player1 << " current balance: " << player1Storage << endl;

											userPlayer = 1;
										}
									}
								}
								else if (userResponse == "earn")
								{
									cout << "How many pets do you have?" << endl;
									cin >> userInput5;

									switch (userInput5) // Updates player bank accounts based off of pet card.
									{
									case 0:
										player2Storage += 0; // If they currently have no pets.

										cout << player2 << " current balance: " << player2Storage << endl;
										cout << player2 << " current board position: " << player2Position << endl;

										userPlayer = 1;
										break;
									case 1:
										player2Storage += 10000;

										cout << player2 << " current balance: " << player2Storage << endl;
										cout << player2 << " current board position: " << player2Position << endl;

										userPlayer = 1;
										break;
									case 2:
										player2Storage += 20000;

										cout << player2 << " current balance: " << player2Storage << endl;
										cout << player2 << " current board position: " << player2Position << endl;

										userPlayer = 1;
										break;
									case 3:
										player2Storage += 30000;

										cout << player2 << " current balance: " << player2Storage << endl;
										cout << player2 << " current board position: " << player2Position << endl;

										userPlayer = 1;
										break;
									case 4:
										player2Storage += 40000;

										cout << player2 << " current balance: " << player2Storage << endl;
										cout << player2 << " current board position: " << player2Position << endl;

										userPlayer = 1;
										break;
									case 5:
										player2Storage += 50000;

										cout << player2 << " current balance: " << player2Storage << endl;
										cout << player2 << " current board position: " << player2Position << endl;

										userPlayer = 1;
										break;
									}
								}
								else if (userResponse == "lose")
								{
									cout << "How many pets do you have?" << endl;
									cin >> userInput5;

									switch (userInput5) // Opposite
									{
									case 0:
										player2Storage -= 0;

										cout << player2 << " current balance: " << player2Storage << endl;
										cout << player2 << " current board position: " << player2Position << endl;

										userPlayer = 1;
										break;
									case 1:
										player2Storage -= 10000;

										cout << player2 << " current balance: " << player2Storage << endl;
										cout << player2 << " current board position: " << player2Position << endl;

										userPlayer = 1;
										break;
									case 2:
										player2Storage -= 20000;

										cout << player2 << " current balance: " << player2Storage << endl;
										cout << player2 << " current board position: " << player2Position << endl;

										userPlayer = 1;
										break;
									case 3:
										player2Storage -= 30000;

										cout << player2 << " current balance: " << player2Storage << endl;
										cout << player2 << " current board position: " << player2Position << endl;

										userPlayer = 1;
										break;
									case 4:
										player2Storage -= 40000;

										cout << player2 << " current balance: " << player2Storage << endl;
										cout << player2 << " current board position: " << player2Position << endl;

										userPlayer = 1;
										break;
									case 5:
										player2Storage -= 50000;

										cout << player2 << " current balance: " << player2Storage << endl;
										cout << player2 << " current board position: " << player2Position << endl;

										userPlayer = 1;
										break;
									}
								}
							}
						}
					}
				}
				if (userPlayer == 1)
				{
					cout << endl;
					cout << player1 << " enter 'spin' to see how many spaces you move." << endl;
					srand(time(0));
					cin >> userResponse;

					if (userResponse == "spin" || "Spin")
					{
						Spinner SpinTheWheelOfFortune;
						SpinTheWheelOfFortune.randomSpin();

						cout << "What did you roll?" << endl;
						cin >> userInput3;

						switch (userInput3) // Updating player position.
						{
						case 1:
							player1Position += 1;
							break;
						case 2:
							player1Position += 2;
							break;
						case 3:
							player1Position += 3;
							break;
						case 4:
							player1Position += 4;
							break;
						case 5:
							player1Position += 5;
							break;
						case 6:
							player1Position += 6;
							break;
						case 7:
							player1Position += 7;
							break;
						case 8:
							player1Position += 8;
							break;
						case 9:
							player1Position += 9;
							break;
						case 10:
							player1Position += 10;
							break;
						}
					}

					cout << "Space 11 is graduation." << endl;
					cout << "Spaces 12-16 are action spaces." << endl;
					cout << "Space 17 is a payay space." << endl;
					cout << "Space 18 is a pet space." << endl;
					cout << "Space 19 is a spin to win space." << endl;
					cout << "Space 20 is an action space." << endl;
					cout << endl;
					cout << "If you landed on an action space, enter 'action'." << endl;
					cout << "If you landed on a pet space, enter 'pet'." << endl;
					cout << "If you landed on graduation, enter 'graduation'." << endl;
					cout << "If you landed on a pay-day-space, enter 'pay'." << endl;
					cout << "If you landed on a spin-to-win space, enter 'win'." << endl;
					cin >> userResponse;

					if (userResponse == "action" || "Action")
					{
						cout << "You landed on an action space." << endl;
						cout << "Enter 'draw' to pick up a random action card." << endl;
						cin >> userResponse;
						cout << endl;

						if (userResponse == "draw" || "Draw")
						{
							Action randAction;
							randAction.ActionCards();

							cout << endl;
							cout << "INITIAL INSTRUCTION" << endl;
							cout << "-------------------" << endl;
							cout << "What did your card tell you to do?" << endl;
							cout << endl;
							cout << "'pay another player', 'pay the bank', 'highest spinner gets paid', 'collect from the bank', 'collect from another player' " << endl;
							cout << "'spin a certain color', 'fired', 'spin a certain number to get paid', '10k x some ammount'." << endl;
							cout << "Here are a list of commands that you should use after you have pulled an action card:" << endl;
							cout << "'pay'--to pay another player." << endl;
							cout << "'give'--to pay the bank." << endl;
							cout << "'highest'--highest spinner gets payed." << endl;
							cout << "'collect'--collect from bank" << endl;
							cout << "'player'--collect from player" << endl;
							cout << "'color'--spin a color" << endl;
							cout << "'fired'" << endl;
							cout << "'number'--spin a number" << endl;
							cout << "'ten'--10 x some ammount of money." << endl;
							cout << endl;
							cout << "So . . . what did your card tell you to do?" << endl;
							cin >> userResponse;

							if (userResponse == "pay")
							{
								cout << "How much do you owe the other player?" << endl;
								cin >> userInput3;

								player1Storage -= userInput3;
								player2Storage += userInput3;

								cout << player1 << " current balance: " << player1Storage << endl;
								cout << player1 << " current board position: " << player1Position << endl;
								cout << player2 << " current balance: " << player2Storage << endl;

								userPlayer = 2;
							}
							else if (userResponse == "give")
							{
								cout << "How much do you owe the bank?" << endl;
								cin >> userInput3;

								player1Storage -= userInput3;

								cout << player1 << " current balance: " << player1Storage << endl;
								cout << player1 << " current board position: " << player1Position << endl;

								userPlayer = 2;
							}
							else if (userResponse == "highest")
							{
								cout << player1 << " please 'spin' the wheel for both players." << endl;
								srand(time(0));
								cin >> userResponse;

								if (userResponse == "spin" || "Spin")
								{
									for (int i = 0; i < 2; ++i)
									{
										Spinner SpinTheWheelOfFortune;
										SpinTheWheelOfFortune.randomSpin();
									}

									cout << player1 << ", which turn had the highest roll?" << endl;
									cin >> userInput4;

									if (userInput4 == 1)
									{
										cout << "How much does " << player2 << " owe you?" << endl;
										cin >> userInput5;

										player1Storage += userInput5;
										player2Storage -= userInput5;

										cout << player1 << " current balance: " << player1Storage << endl;
										cout << player1 << " current board position: " << player1Position << endl;
										cout << endl;
										cout << player2 << " current balance: " << player2Storage << endl;

										userPlayer = 2;
									}
									else if (userInput4 == 2)
									{
										cout << "How much does " << player1 << " owe you?" << endl;
										cin >> userInput5;

										player1Storage -= userInput5;
										player2Storage += userInput5;

										cout << player1 << " current balance: " << player1Storage << endl;
										cout << player1 << " current board position: " << player1Position << endl;
										cout << endl;
										cout << player2 << " current balance: " << player2Storage << endl;

										userPlayer = 2;
									}
								}
							}
							else if (userResponse == "collect")
							{
								cout << "How much does the bank owe you?" << endl;
								cin >> userInput5;

								player1Storage += userInput5;

								cout << player1 << " current balance: " << player1Storage << endl;
								cout << player1 << " current board position: " << player1Position << endl;

								userPlayer = 2;
							}
							else if (userResponse == "player")
							{
								cout << "How much does " << player2 << " owe you?" << endl;
								cin >> userInput5;

								player1Storage += userInput5;
								player2Storage -= userInput5;

								cout << player1 << " current balance: " << player1Storage << endl;
								cout << player1 << " current board position: " << player1Position << endl;
								cout << player2 << " current balance: " << player2Storage << endl;

								userPlayer = 2;
							}
							else if (userResponse == "color")
							{
								cout << player1 << " please 'spin' the wheel." << endl;
								srand(time(0));
								cin >> userResponse;

								if (userResponse == "spin" || "Spin")
								{
									for (int i = 0; i < 1; ++i)
									{
										Spinner SpinTheWheelOfFortune;
										SpinTheWheelOfFortune.randomSpin();
									}

									cout << "What number did you spin?" << endl;
									cin >> userInput5;

									if (userInput5 == 1 || userInput5 == 3 || userInput5 == 5 || userInput5 == 7 || userInput5 == 9)
									{
										const int RED_VAL = 40000;

										cout << "You landed a red space." << endl;
										cout << "You get an automatic 40k added to your bank account." << endl;

										player1Storage += RED_VAL;

										cout << player1 << " current balance: " << player1Storage << endl;
										cout << player1 << " current board position: " << player1Position << endl;

										userPlayer = 2;
									}
									else if (userInput5 == 2 || userInput5 == 4 || userInput5 == 6 || userInput5 == 8 || userInput5 == 10)
									{
										const int BLACK_VAL = 50000;

										cout << "You landed a black space." << endl;
										cout << "You get an automatic 50k added to your bank account." << endl;

										player1Storage += BLACK_VAL;

										cout << player1 << " current balance: " << player1Storage << endl;
										cout << player1 << " current board position: " << player1Position << endl;

										userPlayer = 2;
									}
								}
							}
							else if (userResponse == "fired")
							{
								cout << "You were fired from your job." << endl;
								cout << "If you do not have a job yet, this does not apply to you." << endl;
								cout << "Please press 'c' to ignore." << endl;
								cout << "However, if this does apply to you--press 'v' to continue." << endl;
								cin >> userResponseSub2;

								if (userResponseSub2 == 'c')
								{
									userPlayer = 2;
								}
								else if (userResponseSub2 == 'v')
								{
									cout << "Please 'draw' another career card." << endl;
									cin >> userResponse;

									if (userResponse == "draw")
									{
										Career randCareer;
										randCareer.CareerCards();
									}

									cout << "This is your new career." << endl;
									cout << "What is your new salary?" << endl;
									cin >> userInput5;

									player1Salary = userInput5;

									cout << player1 << " your salary is: " << player1Salary << endl;
									cout << player1 << " current board position: " << player1Position << endl;

									userPlayer = 2;
								}
							}
							else if (userResponse == "number")
							{
								cout << "Does your card want all players to spin or just yourself?" << endl;
								cin >> userResponse;

								if (userResponse == "me")
								{
									cout << player1 << " please 'spin' the wheel." << endl;
									srand(time(0));
									cin >> userResponse;

									if (userResponse == "spin" || "Spin")
									{
										for (int i = 0; i < 1; ++i)
										{
											Spinner SpinTheWheelOfFortune;
											SpinTheWheelOfFortune.randomSpin();
										}

										cout << "What number did you spin?" << endl;
										cin >> userInput5;

										if (userInput5 >= 1 && userInput5 <= 5)
										{
											player1Storage += 50000;

											cout << player1 << " current balance: " << player1Storage << endl;
											cout << player1 << " current board position: " << player1Position << endl;

											userPlayer = 2;
										}
										else if (userInput5 >= 5 && userInput5 <= 10)
										{
											player1Storage += 100000;

											cout << player1 << " current balance: " << player1Storage << endl;
											cout << player1 << " current board position: " << player1Position << endl;

											userPlayer = 2;
										}
									}
								}
								else if (userResponse == "all")
								{
									cout << player1 << " please 'spin' the wheel." << endl;
									srand(time(0));
									cin >> userResponse;

									if (userResponse == "spin" || "Spin")
									{
										for (int i = 0; i < 1; ++i)
										{
											Spinner SpinTheWheelOfFortune;
											SpinTheWheelOfFortune.randomSpin();
										}

										cout << "What number did you spin?" << endl;
										cin >> userInput5;

										if (userInput5 >= 1 && userInput5 <= 5)
										{
											player1Storage += 50000;

											cout << player1 << " current balance: " << player1Storage << endl;
											cout << player1 << " current board position: " << player1Position << endl;
										}
										else if (userInput5 >= 5 && userInput5 <= 10)
										{
											player1Storage += 100000;

											cout << player1 << " current balance: " << player1Storage << endl;
											cout << player1 << " current board position: " << player1Position << endl;
										}
										cout << player2 << " please 'spin' the wheel." << endl;
										srand(time(0));
										cin >> userResponse;

										if (userResponse == "spin" || "Spin")
										{
											for (int i = 0; i < 1; ++i)
											{
												Spinner SpinTheWheelOfFortune;
												SpinTheWheelOfFortune.randomSpin();
											}

											cout << "What number did you spin?" << endl;
											cin >> userInput5;

											if (userInput5 >= 1 && userInput5 <= 5)
											{
												player2Storage += 50000;

												cout << player2 << " current balance: " << player2Storage << endl;

												userPlayer = 2;
											}
											else if (userInput5 >= 5 && userInput5 <= 10)
											{
												player2Storage += 100000;

												cout << player2 << " current balance: " << player2Storage << endl;

												userPlayer = 2;
											}
										}
									}
								}
							}
							else if (userResponse == "ten")
							{
								cout << player1 << ", 'spin' the wheel." << endl;
								srand(time(0));
								cin >> userResponse;

								if (userResponse == "spin" || "Spin")
								{
									for (int i = 0; i < 1; ++i)
									{
										Spinner SpinTheWheelOfFortune;
										SpinTheWheelOfFortune.randomSpin();
									}

									cout << "What did you spin?" << endl;
									cin >> userInput5;

									switch (userInput5)
									{
									case 1:
										num = 10000 * userInput5;

										player1Storage += num;

										cout << player1 << " current balance: " << player1Storage << endl;
										cout << player1 << " current board position: " << player1Position << endl;

										userPlayer = 2;
										break;
									case 2:
										num = 10000 * userInput5;

										player1Storage += num;

										cout << player1 << " current balance: " << player1Storage << endl;
										cout << player1 << " current board position: " << player1Position << endl;

										userPlayer = 2;
										break;
									case 3:
										num = 10000 * userInput5;

										player1Storage += num;

										cout << player1 << " current balance: " << player1Storage << endl;
										cout << player1 << " current board position: " << player1Position << endl;

										userPlayer = 2;
										break;
									case 4:
										num = 10000 * userInput5;

										player1Storage += num;

										cout << player1 << " current balance: " << player1Storage << endl;
										cout << player1 << " current board position: " << player1Position << endl;

										userPlayer = 2;
										break;
									case 5:
										num = 10000 * userInput5;

										player1Storage += num;

										cout << player1 << " current balance: " << player1Storage << endl;
										cout << player1 << " current board position: " << player1Position << endl;

										userPlayer = 2;
										break;
									case 6:
										num = 10000 * userInput5;

										player1Storage += num;

										cout << player1 << " current balance: " << player1Storage << endl;
										cout << player1 << " current board position: " << player1Position << endl;

										userPlayer = 2;
										break;
									case 7:
										num = 10000 * userInput5;

										player1Storage += num;

										cout << player1 << " current balance: " << player1Storage << endl;
										cout << player1 << " current board position: " << player1Position << endl;

										userPlayer = 2;
										break;
									case 8:
										num = 10000 * userInput5;

										player1Storage += num;

										cout << player1 << " current balance: " << player1Storage << endl;
										cout << player1 << " current board position: " << player1Position << endl;

										userPlayer = 2;
										break;
									case 9:
										num = 10000 * userInput5;

										player1Storage += num;

										cout << player1 << " current balance: " << player1Storage << endl;
										cout << player1 << " current board position: " << player1Position << endl;

										userPlayer = 2;
										break;
									case 10:
										num = 10000 * userInput5;

										player1Storage += num;

										cout << player1 << " current balance: " << player1Storage << endl;
										cout << player1 << " current board position: " << player1Position << endl;

										userPlayer = 2;
										break;
									}
								}
							}
						}
					}
					else if (userResponse == "pet" || "Pet")
					{
						cout << "You landed on a pet space." << endl;
						cout << "Enter 'draw' to pick up a random pet card." << endl;
						cin >> userResponse;
						cout << endl;

						if (userResponse == "draw" || "Draw")
						{
							Pet randPet;
							randPet.PetCards();

							cout << endl;
							cout << "INITIAL INSTRUCTION" << endl;
							cout << "-------------------" << endl;
							cout << "What did your card tell you to do?" << endl;
							cout << endl;
							cout << "'pay another player', 'pay the bank', 'collect from the bank', 'collect from another player' " << endl;
							cout << ",'earn some ammount of money for each pet you have', 'give some ammount of money to the bank for each pet you have'." << endl;
							cout << "Here are a list of commands that you should use after you have pulled an action card:" << endl;
							cout << "'pay'--to pay another player." << endl;
							cout << "'give'--to pay the bank." << endl;
							cout << "'collect'--collect from bank" << endl;
							cout << "'player'--collect from player" << endl;
							cout << "'number'--spin a number" << endl;
							cout << "'earn'--earn money based off how many pets you have." << endl;
							cout << "'lose'--pay the bank based off how many pets you have." << endl;
							cout << endl;
							cout << "So . . . what did your card tell you to do?" << endl;
							cin >> userResponse;

							if (userResponse == "pay")
							{
								cout << "How much do you owe the other player?" << endl;
								cin >> userInput3;

								player1Storage -= userInput3;
								player2Storage += userInput3;

								cout << player1 << " current balance: " << player1Storage << endl;
								cout << player1 << " current board position: " << player1Position << endl;
								cout << player2 << " current balance: " << player2Storage << endl;

								userPlayer = 2;
							}
							else if (userResponse == "give")
							{
								cout << "How much do you owe the bank?" << endl;
								cin >> userInput3;

								player1Storage -= userInput3;

								cout << player1 << " current balance: " << player1Storage << endl;
								cout << player1 << " current board position: " << player1Position << endl;

								userPlayer = 2;
							}
							else if (userResponse == "collect")
							{
								cout << "How much does the bank owe you?" << endl;
								cin >> userInput5;

								player1Storage += userInput5;

								cout << player1 << " current balance: " << player1Storage << endl;
								cout << player1 << " current board position: " << player1Position << endl;

								userPlayer = 2;
							}
							else if (userResponse == "player")
							{
								cout << "How much does " << player2 << " owe you?" << endl;
								cin >> userInput5;

								player1Storage += userInput5;
								player2Storage -= userInput5;

								cout << player1 << " current balance: " << player1Storage << endl;
								cout << player1 << " current board position: " << player1Position << endl;
								cout << player2 << " current balance: " << player2Storage << endl;

								userPlayer = 2;
							}
							else if (userResponse == "highest")
							{
								cout << player1 << " please 'spin' the wheel for both players." << endl;
								srand(time(0));
								cin >> userResponse;

								if (userResponse == "spin" || "Spin")
								{
									for (int i = 0; i < 2; ++i)
									{
										Spinner SpinTheWheelOfFortune;
										SpinTheWheelOfFortune.randomSpin();
									}

									cout << player1 << ", which turn had the highest roll?" << endl;
									cin >> userInput4;

									if (userInput4 == 1)
									{
										cout << "How much does " << player2 << " owe you?" << endl;
										cin >> userInput5;

										player1Storage += userInput5;
										player2Storage -= userInput5;

										cout << player1 << " current balance: " << player1Storage << endl;
										cout << player1 << " current board position: " << player1Position << endl;
										cout << player2 << " current balance: " << player2Storage << endl;

										userPlayer = 2;
									}
									else if (userInput4 == 2)
									{
										cout << "How much does " << player1 << " owe you?" << endl;
										cin >> userInput5;

										player1Storage -= userInput5;
										player2Storage += userInput5;

										cout << player1 << " current balance: " << player1Storage << endl;
										cout << player1 << " current board position: " << player1Position << endl;
										cout << player2 << " current balance: " << player2Storage << endl;

										userPlayer = 2;
									}
								}
							}
							else if (userResponse == "earn")
							{
								cout << "How many pets do you have?" << endl;
								cin >> userInput5;

								switch (userInput5)
								{
								case 0:
									player1Storage += 0;

									cout << player1 << " current balance: " << player1Storage << endl;
									cout << player1 << " current board position: " << player1Position << endl;

									userPlayer = 2;
									break;
								case 1:
									player1Storage += 10000;

									cout << player1 << " current balance: " << player1Storage << endl;
									cout << player1 << " current board position: " << player1Position << endl;

									userPlayer = 2;
									break;
								case 2:
									player1Storage += 20000;

									cout << player1 << " current balance: " << player1Storage << endl;
									cout << player1 << " current board position: " << player1Position << endl;

									userPlayer = 2;
									break;
								case 3:
									player1Storage += 30000;

									cout << player1 << " current balance: " << player1Storage << endl;
									cout << player1 << " current board position: " << player1Position << endl;

									userPlayer = 2;
									break;
								case 4:
									player1Storage += 40000;

									cout << player1 << " current balance: " << player1Storage << endl;
									cout << player1 << " current board position: " << player1Position << endl;

									userPlayer = 2;
									break;
								case 5:
									player1Storage += 50000;

									cout << player1 << " current balance: " << player1Storage << endl;
									cout << player1 << " current board position: " << player1Position << endl;

									userPlayer = 2;
									break;
								}
							}
							else if (userResponse == "lose")
							{
								cout << "How many pets do you have?" << endl;
								cin >> userInput5;

								switch (userInput5)
								{
								case 0:
									player1Storage -= 0;

									cout << player1 << " current balance: " << player1Storage << endl;
									cout << player1 << " current board position: " << player1Position << endl;

									userPlayer = 2;
									break;
								case 1:
									player1Storage -= 10000;

									cout << player1 << " current balance: " << player1Storage << endl;
									cout << player1 << " current board position: " << player1Position << endl;

									userPlayer = 2;
									break;
								case 2:
									player1Storage -= 20000;

									cout << player1 << " current balance: " << player1Storage << endl;
									cout << player1 << " current board position: " << player1Position << endl;

									userPlayer = 2;
									break;
								case 3:
									player1Storage -= 30000;

									cout << player1 << " current balance: " << player1Storage << endl;
									cout << player1 << " current board position: " << player1Position << endl;

									userPlayer = 2;
									break;
								case 4:
									player1Storage -= 40000;

									cout << player1 << " current balance: " << player1Storage << endl;
									cout << player1 << " current board position: " << player1Position << endl;

									userPlayer = 2;
									break;
								case 5:
									player1Storage -= 50000;

									cout << player1 << " current balance: " << player1Storage << endl;
									cout << player1 << " current board position: " << player1Position << endl;

									userPlayer = 2;
									break;
								}
							}
						}
					}
					else if (userResponse == "graduation") // User questions based off of their job card.
					{
						cout << "Stop: Graduation!" << endl;
						cout << "Enter 'draw' for your new job." << endl;
						cin >> userResponse;

						if (userResponse == "draw" || "Draw")
						{
							CollegeCareer randCareer;
							randCareer.CollegeCareerCards();

							cout << "What is your salary?" << endl;
							cin >> player1Salary;

							cout << player1 << ", salary: " << player1Salary << endl;

							userPlayer = 2;
						}
					}
					else if (userResponse == "pay")
					{
						cout << "You landed on a payday space." << endl;
						cout << "If you already have your job, please state what your job is." << endl;
						cout << "If you don't have a job yet, enter 'continue'." << endl;
						cin >> userResponse;

						if (userResponse == "lawyer" || "Lawyer") // Updates player's bank account and job status.
						{
							cout << "Take your salary and an additional 100k bonus." << endl;
							cout << "The bank owes you " << player1Salary << endl;

							player1Storage += player1Salary;

							cout << "Current money: " << player1Salary << endl;

							userPlayer = 2;
						}
						else if (userResponse == "doctor" || "Doctor")
						{
							cout << "Take your salary and an additional 100k bonus." << endl;
							cout << "The bank owes you " << player1Salary << endl;

							player1Storage += player1Salary;

							cout << "Current money: " << player1Salary << endl;

							userPlayer = 2;
						}
						else if (userResponse == "video-game")
						{
							cout << "Take your salary and an additional 100k bonus." << endl;
							cout << "The bank owes you " << player1Salary << endl;

							player1Storage += player1Salary;

							cout << "Current money: " << player1Salary << endl;

							userPlayer = 2;
						}
						else if (userResponse == "secret-agent")
						{
							cout << "Take your salary and an additional 100k bonus." << endl;
							cout << "The bank owes you " << player1Salary << endl;

							player1Storage += player1Salary;

							cout << "Current money: " << player1Salary << endl;

							userPlayer = 2;
						}
						else if (userResponse == "teacher" || "Teacher")
						{
							cout << "Take your salary and an additional 100k bonus." << endl;
							cout << "The bank owes you " << player1Salary << endl;

							player1Storage += player1Salary;

							cout << "Current money: " << player1Salary << endl;

							userPlayer = 2;
						}
						else if (userResponse == "scientist" || "Scientist")
						{
							cout << "Take your salary and an additional 100k bonus." << endl;
							cout << "The bank owes you " << player1Salary << endl;

							player1Storage += player1Salary;

							cout << "Current money: " << player1Salary << endl;

							userPlayer = 2;
						}
						else if (userResponse == "vet" || "Vet")
						{
							cout << "Take your salary and an additional 100k bonus." << endl;
							cout << "The bank owes you " << player1Salary << endl;

							player1Storage += player1Salary;

							cout << "Current money: " << player1Salary << endl;

							userPlayer = 2;
						}
						else if (userResponse == "fashion-designer")
						{
							cout << "Take your salary and an additional 100k bonus." << endl;
							cout << "The bank owes you " << player1Salary << endl;

							player1Storage += player1Salary;

							cout << "Current money: " << player1Salary << endl;

							userPlayer = 2;
						}
						else if (userResponse == "continue")
						{
							cout << "Firstly, you need your new job." << endl;
							cout << "Enter 'draw' for your new job." << endl;
							cin >> userResponse;

							if (userResponse == "draw" || "Draw")
							{
								CollegeCareer randCareer;
								randCareer.CollegeCareerCards();

								cout << "What is your salary?" << endl;
								cin >> player1Salary;
								cout << player1 << ", salary: " << player1Salary << endl;
								cout << "What is your job?" << endl;
								cin >> userResponse;
							}
							if (userResponse == "lawyer" || "Lawyer")
							{
								cout << "Take your salary and an additional 100k bonus." << endl;
								cout << "The bank owes you " << player1Salary << endl;

								player1Storage += player1Salary;

								cout << "Current money: " << player1Salary << endl;

								userPlayer = 2;
							}
							else if (userResponse == "doctor" || "Doctor")
							{
								cout << "Take your salary and an additional 100k bonus." << endl;
								cout << "The bank owes you " << player1Salary << endl;

								player1Storage += player1Salary;

								cout << "Current money: " << player1Salary << endl;

								userPlayer = 2;
							}
							else if (userResponse == "video-game")
							{
								cout << "Take your salary and an additional 100k bonus." << endl;
								cout << "The bank owes you " << player1Salary << endl;

								player1Storage += player1Salary;

								cout << "Current money: " << player1Salary << endl;

								userPlayer = 2;
							}
							else if (userResponse == "secret-agent")
							{
								cout << "Take your salary and an additional 100k bonus." << endl;
								cout << "The bank owes you " << player1Salary << endl;

								player1Storage += player1Salary;

								cout << "Current money: " << player1Salary << endl;

								userPlayer = 2;
							}
							else if (userResponse == "teacher" || "Teacher")
							{
								cout << "Take your salary and an additional 100k bonus." << endl;
								cout << "The bank owes you " << player1Salary << endl;

								player1Storage += player1Salary;

								cout << "Current money: " << player1Salary << endl;

								userPlayer = 2;
							}
							else if (userResponse == "scientist" || "Scientist")
							{
								cout << "Take your salary and an additional 100k bonus." << endl;
								cout << "The bank owes you " << player1Salary << endl;

								player1Storage += player1Salary;

								cout << "Current money: " << player1Salary << endl;

								userPlayer = 2;
							}
							else if (userResponse == "vet" || "Vet")
							{
								cout << "Take your salary and an additional 100k bonus." << endl;
								cout << "The bank owes you " << player1Salary << endl;

								player1Storage += player1Salary;

								cout << "Current money: " << player1Salary << endl;

								userPlayer = 2;
							}
							else if (userResponse == "fashion-designer")
							{
								cout << "Take your salary and an additional 100k bonus." << endl;
								cout << "The bank owes you " << player1Salary << endl;

								player1Storage += player1Salary;

								cout << "Current money: " << player1Salary << endl;

								userPlayer = 2;
							}
						}
					}
					else if (userResponse == "win") // Spin to win determined through user-input.
					{
						cout << "Who landed on the spin-to-win space?" << endl;
						cin >> userResponse;

						if (userResponse == "player1")
						{
							cout << player1 << ", choose two numbers on the wheel you think you have a chance of spinning and memorize them." << endl;
							cout << endl;
							cout << player2 << ", choose one number on the wheel you think yo have a chance of spinning and memorize it." << endl;
							cout << player1 << ", 'spin' the wheel until one of the numbers is landed upon." << endl;
							cin >> userResponse;

							if (userResponse == "spin" || "Spin")
							{
								srand(time(0));

								for (int i = 0; i < 1; ++i)
								{
									Spinner SpinTheWheelOfFortune;
									SpinTheWheelOfFortune.randomSpin();

									cout << "If you landed on one of the nubmers, enter 'c' to move on." << endl;
									cout << "If you did not land on one of the numbers, enter 's' to keep spinning." << endl;
									cin >> userResponseSub2;

									if (userResponseSub2 == 'c')
									{
										cout << "Whose number was chosen? (player 1 or player 2)" << endl;
										cin >> userResponse;

										if (userResponse == "player1")
										{
											cout << player1 << " gets 200k" << endl;

											player1Storage += 200000;

											cout << player1 << ", current balance: " << player1Storage << endl;
											cout << player1 << ", current position: " << player1Position << endl;

											userPlayer = 2;
										}
										else if (userResponse == "player2")
										{
											cout << player2 << " gets 200k" << endl;

											player2Storage += 200000;

											cout << player2 << ", current balance: " << player1Storage << endl;

											userPlayer = 2;
										}
									}
									else if (userResponseSub2 == 's')
									{
										continue; // If player's have not landed on one of the guessed spots, they can continue to spin until they do.
									}
								}
							}
						}
					}
				}
				if (userPlayer == 2)
				{
					cout << endl;
					cout << player2 << " enter 'spin' to see how many spaces you move." << endl;
					srand(time(0));
					cin >> userResponse;

					if (userResponse == "spin" || "Spin")
					{
						Spinner SpinTheWheelOfFortune;
						SpinTheWheelOfFortune.randomSpin();

						cout << "What did you roll?" << endl;
						cin >> userInput3;

						switch (userInput3) // Updating position.
						{
						case 1:
							player2Position += 1;
							break;
						case 2:
							player2Position += 2;
							break;
						case 3:
							player2Position += 3;
							break;
						case 4:
							player2Position += 4;
							break;
						case 5:
							player2Position += 5;
							break;
						case 6:
							player2Position += 6;
							break;
						case 7:
							player2Position += 7;
							break;
						case 8:
							player2Position += 8;
							break;
						case 9:
							player2Position += 9;
							break;
						case 10:
							player2Position += 10;
							break;
						}
					}

					cout << "Space 11 is graduation." << endl;
					cout << "Spaces 12-16 are action spaces." << endl;
					cout << "Space 17 is a payay space." << endl;
					cout << "Space 18 is a pet space." << endl;
					cout << "Space 19 is a spin to win space." << endl;
					cout << "Space 20 is an action space." << endl;
					cout << endl;
					cout << "If you landed on an action space, enter 'action'." << endl;
					cout << "If you landed on a pet space, enter 'pet'." << endl;
					cout << "If you landed on graduation, enter 'graduation'." << endl;
					cout << "If you landed on a pay-day-space, enter 'pay'." << endl;
					cout << "If you landed on a spin-to-win space, enter 'win'." << endl;
					cin >> userResponse;

					if (userResponse == "action" || "Action")
					{
						cout << "You landed on an action space." << endl;
						cout << "Enter 'draw' to pick up a random action card." << endl;
						cin >> userResponse;
						cout << endl;

						if (userResponse == "draw" || "Draw")
						{
							Action randAction;
							randAction.ActionCards();

							cout << endl;
							cout << "INITIAL INSTRUCTION" << endl;
							cout << "-------------------" << endl;
							cout << "What did your card tell you to do?" << endl;
							cout << endl;
							cout << "'pay another player', 'pay the bank', 'highest spinner gets paid', 'collect from the bank', 'collect from another player' " << endl;
							cout << "'spin a certain color', 'fired', 'spin a certain number to get paid', '10k x some ammount'." << endl;
							cout << "Here are a list of commands that you should use after you have pulled an action card:" << endl;
							cout << "'pay'--to pay another player." << endl;
							cout << "'give'--to pay the bank." << endl;
							cout << "'highest'--highest spinner gets payed." << endl;
							cout << "'collect'--collect from bank" << endl;
							cout << "'player'--collect from player" << endl;
							cout << "'color'--spin a color" << endl;
							cout << "'fired'" << endl;
							cout << "'number'--spin a number" << endl;
							cout << "'ten'--10 x some ammount of money." << endl;
							cout << endl;
							cout << "So . . . what did your card tell you to do?" << endl;
							cin >> userResponse;

							if (userResponse == "pay")
							{
								cout << "How much do you owe the other player?" << endl;
								cin >> userInput3;

								player2Storage -= userInput3;
								player1Storage += userInput3;

								cout << player2 << " current balance: " << player2Storage << endl;
								cout << player2 << " current board position: " << player2Position << endl;
								cout << player1 << " current balance: " << player1Storage << endl;

								userPlayer = 1;
							}
							else if (userResponse == "give")
							{
								cout << "How much do you owe the bank?" << endl;
								cin >> userInput3;

								player2Storage -= userInput3;

								cout << player2 << " current balance: " << player2Storage << endl;
								cout << player2 << " current board position: " << player2Position << endl;

								userPlayer = 1;
							}
							else if (userResponse == "highest")
							{
								cout << player2 << " please 'spin' the wheel for both players." << endl;
								srand(time(0));
								cin >> userResponse;

								if (userResponse == "spin" || "Spin")
								{
									for (int i = 0; i < 2; ++i)
									{
										Spinner SpinTheWheelOfFortune;
										SpinTheWheelOfFortune.randomSpin();
									}

									cout << player2 << ", which turn had the highest roll?" << endl;
									cin >> userInput4;

									if (userInput4 == 1)
									{
										cout << "How much does " << player1 << " owe you?" << endl;
										cin >> userInput5;

										player2Storage += userInput5;
										player1Storage -= userInput5;

										cout << player2 << " current balance: " << player2Storage << endl;
										cout << player2 << " current board position: " << player2Position << endl;
										cout << endl;
										cout << player1 << " current balance: " << player1Storage << endl;

										userPlayer = 1;
									}
									else if (userInput4 == 2)
									{
										cout << "How much does " << player2 << " owe you?" << endl;
										cin >> userInput5;

										player2Storage -= userInput5;
										player1Storage += userInput5;

										cout << player2 << " current balance: " << player2Storage << endl;
										cout << player2 << " current board position: " << player2Position << endl;
										cout << endl;
										cout << player1 << " current balance: " << player1Storage << endl;

										userPlayer = 1;
									}
								}
							}
							else if (userResponse == "collect")
							{
								cout << "How much does the bank owe you?" << endl;
								cin >> userInput5;

								player2Storage += userInput5;

								cout << player2 << " current balance: " << player2Storage << endl;
								cout << player2 << " current board position: " << player2Position << endl;

								userPlayer = 1;
							}
							else if (userResponse == "player")
							{
								cout << "How much does " << player1 << " owe you?" << endl;
								cin >> userInput5;

								player2Storage += userInput5;
								player1Storage -= userInput5;

								cout << player2 << " current balance: " << player2Storage << endl;
								cout << player2 << " current board position: " << player2Position << endl;
								cout << player1 << " current balance: " << player1Storage << endl;

								userPlayer = 1;
							}
							else if (userResponse == "color")
							{
								cout << player2 << " please 'spin' the wheel." << endl;
								srand(time(0));
								cin >> userResponse;

								if (userResponse == "spin" || "Spin")
								{
									for (int i = 0; i < 1; ++i)
									{
										Spinner SpinTheWheelOfFortune;
										SpinTheWheelOfFortune.randomSpin();
									}

									cout << "What number did you spin?" << endl;
									cin >> userInput5;

									if (userInput5 == 1 || userInput5 == 3 || userInput5 == 5 || userInput5 == 7 || userInput5 == 9)
									{
										const int RED_VAL = 40000;

										cout << "You landed a red space." << endl;
										cout << "You get an automatic 40k added to your bank account." << endl;

										player2Storage += RED_VAL;

										cout << player2 << " current balance: " << player2Storage << endl;
										cout << player2 << " current board position: " << player2Position << endl;

										userPlayer = 1;
									}
									else if (userInput5 == 2 || userInput5 == 4 || userInput5 == 6 || userInput5 == 8 || userInput5 == 10)
									{
										const int BLACK_VAL = 50000;

										cout << "You landed a black space." << endl;
										cout << "You get an automatic 50k added to your bank account." << endl;

										player2Storage += BLACK_VAL;

										cout << player2 << " current balance: " << player2Storage << endl;
										cout << player2 << " current board position: " << player2Position << endl;

										userPlayer = 1;
									}
								}
							}
							else if (userResponse == "fired")
							{
								cout << "You were fired from your job." << endl;
								cout << "If you do not have a job yet, this does not apply to you." << endl;
								cout << "Please press 'c' to ignore." << endl;
								cout << "However, if this does apply to you--press 'v' to continue." << endl;
								cin >> userResponseSub2;

								if (userResponseSub2 == 'c')
								{
									userPlayer = 1;
								}
								else if (userResponseSub2 == 'v')
								{
									cout << "Please 'draw' another career card." << endl;
									cin >> userResponse;

									if (userResponse == "draw")
									{
										Career randCareer;
										randCareer.CareerCards();
									}

									cout << "This is your new career." << endl;
									cout << "What is your new salary?" << endl;
									cin >> userInput5;

									player2Salary = userInput5;

									cout << player2 << " your salary is: " << player2Salary << endl;
									cout << player2 << " current board position: " << player2Position << endl;

									userPlayer = 1;
								}
							}
							else if (userResponse == "number")
							{
								cout << "Does your card want all players to spin or just yourself?" << endl;
								cin >> userResponse;

								if (userResponse == "me")
								{
									cout << player2 << " please 'spin' the wheel." << endl;
									srand(time(0));
									cin >> userResponse;

									if (userResponse == "spin" || "Spin")
									{
										for (int i = 0; i < 1; ++i)
										{
											Spinner SpinTheWheelOfFortune;
											SpinTheWheelOfFortune.randomSpin();
										}

										cout << "What number did you spin?" << endl;
										cin >> userInput5;

										if (userInput5 >= 1 && userInput5 <= 5)
										{
											player2Storage += 50000;

											cout << player2 << " current balance: " << player2Storage << endl;
											cout << player2 << " current board position: " << player2Position << endl;

											userPlayer = 1;
										}
										else if (userInput5 >= 5 && userInput5 <= 10)
										{
											player2Storage += 100000;

											cout << player2 << " current balance: " << player2Storage << endl;
											cout << player2 << " current board position: " << player2Position << endl;

											userPlayer = 1;
										}
									}
								}
								else if (userResponse == "all")
								{
									cout << player2 << " please 'spin' the wheel." << endl;
									srand(time(0));
									cin >> userResponse;

									if (userResponse == "spin" || "Spin")
									{
										for (int i = 0; i < 1; ++i)
										{
											Spinner SpinTheWheelOfFortune;
											SpinTheWheelOfFortune.randomSpin();
										}

										cout << "What number did you spin?" << endl;
										cin >> userInput5;

										if (userInput5 >= 1 && userInput5 <= 5)
										{
											player2Storage += 50000;

											cout << player2 << " current balance: " << player2Storage << endl;
											cout << player2 << " current board position: " << player2Position << endl;
										}
										else if (userInput5 >= 5 && userInput5 <= 10)
										{
											player2Storage += 100000;

											cout << player2 << " current balance: " << player2Storage << endl;
											cout << player2 << " current board position: " << player2Position << endl;
										}
										cout << player1 << " please 'spin' the wheel." << endl;
										srand(time(0));
										cin >> userResponse;

										if (userResponse == "spin" || "Spin")
										{
											for (int i = 0; i < 1; ++i)
											{
												Spinner SpinTheWheelOfFortune;
												SpinTheWheelOfFortune.randomSpin();
											}

											cout << "What number did you spin?" << endl;
											cin >> userInput5;

											if (userInput5 >= 1 && userInput5 <= 5)
											{
												player1Storage += 50000;

												cout << player1 << " current balance: " << player1Storage << endl;

												userPlayer = 1;
											}
											else if (userInput5 >= 5 && userInput5 <= 10)
											{
												player1Storage += 100000;

												cout << player1 << " current balance: " << player1Storage << endl;

												userPlayer = 1;
											}
										}
									}
								}
							}
							else if (userResponse == "ten")
							{
								cout << player2 << ", 'spin' the wheel." << endl;
								srand(time(0));
								cin >> userResponse;

								if (userResponse == "spin" || "Spin")
								{
									for (int i = 0; i < 1; ++i)
									{
										Spinner SpinTheWheelOfFortune;
										SpinTheWheelOfFortune.randomSpin();
									}

									cout << "What did you spin?" << endl;
									cin >> userInput5;

									switch (userInput5)
									{
									case 1:
										num = 10000 * userInput5;

										player2Storage += num;

										cout << player2 << " current balance: " << player2Storage << endl;
										cout << player2 << " current board position: " << player2Position << endl;

										userPlayer = 1;
										break;
									case 2:
										num = 10000 * userInput5;

										player2Storage += num;

										cout << player2 << " current balance: " << player2Storage << endl;
										cout << player2 << " current board position: " << player2Position << endl;

										userPlayer = 1;
										break;
									case 3:
										num = 10000 * userInput5;

										player2Storage += num;

										cout << player2 << " current balance: " << player2Storage << endl;
										cout << player2 << " current board position: " << player2Position << endl;

										userPlayer = 1;
										break;
									case 4:
										num = 10000 * userInput5;

										player2Storage += num;

										cout << player2 << " current balance: " << player2Storage << endl;
										cout << player2 << " current board position: " << player2Position << endl;

										userPlayer = 1;
										break;
									case 5:
										num = 10000 * userInput5;

										player2Storage += num;

										cout << player2 << " current balance: " << player2Storage << endl;
										cout << player2 << " current board position: " << player2Position << endl;

										userPlayer = 1;
										break;
									case 6:
										num = 10000 * userInput5;

										player2Storage += num;

										cout << player2 << " current balance: " << player2Storage << endl;
										cout << player2 << " current board position: " << player2Position << endl;

										userPlayer = 1;
										break;
									case 7:
										num = 10000 * userInput5;

										player2Storage += num;

										cout << player2 << " current balance: " << player2Storage << endl;
										cout << player2 << " current board position: " << player2Position << endl;

										userPlayer = 1;
										break;
									case 8:
										num = 10000 * userInput5;

										player2Storage += num;

										cout << player2 << " current balance: " << player2Storage << endl;
										cout << player2 << " current board position: " << player2Position << endl;

										userPlayer = 1;
										break;
									case 9:
										num = 10000 * userInput5;

										player2Storage += num;

										cout << player2 << " current balance: " << player2Storage << endl;
										cout << player2 << " current board position: " << player2Position << endl;

										userPlayer = 1;
										break;
									case 10:
										num = 10000 * userInput5;

										player2Storage += num;

										cout << player2 << " current balance: " << player2Storage << endl;
										cout << player2 << " current board position: " << player2Position << endl;

										userPlayer = 1;
										break;
									}
								}
							}
						}
					}
					else if (userResponse == "pet" || "Pet")
					{
						cout << "You landed on a pet space." << endl;
						cout << "Enter 'draw' to pick up a random pet card." << endl;
						cin >> userResponse;
						cout << endl;

						if (userResponse == "draw" || "Draw")
						{
							Pet randPet;
							randPet.PetCards();

							cout << endl;
							cout << "INITIAL INSTRUCTION" << endl;
							cout << "-------------------" << endl;
							cout << "What did your card tell you to do?" << endl;
							cout << endl;
							cout << "'pay another player', 'pay the bank', 'collect from the bank', 'collect from another player' " << endl;
							cout << ",'earn some ammount of money for each pet you have', 'give some ammount of money to the bank for each pet you have'." << endl;
							cout << "Here are a list of commands that you should use after you have pulled an action card:" << endl;
							cout << "'pay'--to pay another player." << endl;
							cout << "'give'--to pay the bank." << endl;
							cout << "'collect'--collect from bank" << endl;
							cout << "'player'--collect from player" << endl;
							cout << "'number'--spin a number" << endl;
							cout << "'earn'--earn money based off how many pets you have." << endl;
							cout << "'lose'--pay the bank based off how many pets you have." << endl;
							cout << endl;
							cout << "So . . . what did your card tell you to do?" << endl;
							cin >> userResponse;

							if (userResponse == "pay")
							{
								cout << "How much do you owe the other player?" << endl;
								cin >> userInput3;

								player2Storage -= userInput3;
								player1Storage += userInput3;

								cout << player2 << " current balance: " << player2Storage << endl;
								cout << player2 << " current board position: " << player2Position << endl;
								cout << player1 << " current balance: " << player1Storage << endl;

								userPlayer = 1;
							}
							else if (userResponse == "give")
							{
								cout << "How much do you owe the bank?" << endl;
								cin >> userInput3;

								player2Storage -= userInput3;

								cout << player2 << " current balance: " << player2Storage << endl;
								cout << player2 << " current board position: " << player2Position << endl;

								userPlayer = 1;
							}
							else if (userResponse == "collect")
							{
								cout << "How much does the bank owe you?" << endl;
								cin >> userInput5;

								player2Storage += userInput5;

								cout << player2 << " current balance: " << player2Storage << endl;
								cout << player2 << " current board position: " << player2Position << endl;

								userPlayer = 1;
							}
							else if (userResponse == "player")
							{
								cout << "How much does " << player1 << " owe you?" << endl;
								cin >> userInput5;

								player2Storage += userInput5;
								player1Storage -= userInput5;

								cout << player2 << " current balance: " << player2Storage << endl;
								cout << player2 << " current board position: " << player2Position << endl;
								cout << player1 << " current balance: " << player1Storage << endl;

								userPlayer = 1;
							}
							else if (userResponse == "highest")
							{
								cout << player1 << " please 'spin' the wheel for both players." << endl;
								srand(time(0));
								cin >> userResponse;

								if (userResponse == "spin" || "Spin")
								{
									for (int i = 0; i < 2; ++i)
									{
										Spinner SpinTheWheelOfFortune;
										SpinTheWheelOfFortune.randomSpin();
									}

									cout << player2 << ", which turn had the highest roll?" << endl;
									cin >> userInput4;

									if (userInput4 == 1)
									{
										cout << "How much does " << player1 << " owe you?" << endl;
										cin >> userInput5;

										player2Storage += userInput5;
										player1Storage -= userInput5;

										cout << player2 << " current balance: " << player2Storage << endl;
										cout << player2 << " current board position: " << player2Position << endl;
										cout << player1 << " current balance: " << player1Storage << endl;

										userPlayer = 1;
									}
									else if (userInput4 == 2)
									{
										cout << "How much does " << player2 << " owe you?" << endl;
										cin >> userInput5;

										player2Storage -= userInput5;
										player1Storage += userInput5;

										cout << player2 << " current balance: " << player2Storage << endl;
										cout << player2 << " current board position: " << player2Position << endl;
										cout << player1 << " current balance: " << player1Storage << endl;

										userPlayer = 1;
									}
								}
							}
							else if (userResponse == "earn")
							{
								cout << "How many pets do you have?" << endl;
								cin >> userInput5;

								switch (userInput5)
								{
								case 0:
									player2Storage += 0;

									cout << player2 << " current balance: " << player2Storage << endl;
									cout << player2 << " current board position: " << player2Position << endl;

									userPlayer = 1;
									break;
								case 1:
									player2Storage += 10000;

									cout << player2 << " current balance: " << player2Storage << endl;
									cout << player2 << " current board position: " << player2Position << endl;

									userPlayer = 1;
									break;
								case 2:
									player2Storage += 20000;

									cout << player2 << " current balance: " << player2Storage << endl;
									cout << player2 << " current board position: " << player2Position << endl;

									userPlayer = 1;
									break;
								case 3:
									player2Storage += 30000;

									cout << player2 << " current balance: " << player2Storage << endl;
									cout << player2 << " current board position: " << player2Position << endl;

									userPlayer = 1;
									break;
								case 4:
									player2Storage += 40000;

									cout << player2 << " current balance: " << player2Storage << endl;
									cout << player2 << " current board position: " << player2Position << endl;

									userPlayer = 1;
									break;
								case 5:
									player2Storage += 50000;

									cout << player2 << " current balance: " << player2Storage << endl;
									cout << player2 << " current board position: " << player2Position << endl;

									userPlayer = 1;
									break;
								}
							}
							else if (userResponse == "lose")
							{
								cout << "How many pets do you have?" << endl;
								cin >> userInput5;

								switch (userInput5)
								{
								case 0:
									player2Storage -= 0;

									cout << player2 << " current balance: " << player2Storage << endl;
									cout << player2 << " current board position: " << player2Position << endl;

									userPlayer = 1;
									break;
								case 1:
									player2Storage -= 10000;

									cout << player2 << " current balance: " << player2Storage << endl;
									cout << player2 << " current board position: " << player2Position << endl;

									userPlayer = 1;
									break;
								case 2:
									player2Storage -= 20000;

									cout << player2 << " current balance: " << player2Storage << endl;
									cout << player2 << " current board position: " << player2Position << endl;

									userPlayer = 1;
									break;
								case 3:
									player2Storage -= 30000;

									cout << player2 << " current balance: " << player2Storage << endl;
									cout << player2 << " current board position: " << player2Position << endl;

									userPlayer = 1;
									break;
								case 4:
									player2Storage -= 40000;

									cout << player2 << " current balance: " << player2Storage << endl;
									cout << player2 << " current board position: " << player2Position << endl;

									userPlayer = 1;
									break;
								case 5:
									player2Storage -= 50000;

									cout << player2 << " current balance: " << player2Storage << endl;
									cout << player2 << " current board position: " << player2Position << endl;

									userPlayer = 1;
									break;
								}
							}
						}
					}
					else if (userResponse == "graduation")
					{
						cout << "Stop: Graduation!" << endl;
						cout << "Enter 'draw' for your new job." << endl;
						cin >> userResponse;

						if (userResponse == "draw" || "Draw")
						{
							CollegeCareer randCareer;
							randCareer.CollegeCareerCards();

							cout << "What is your salary?" << endl;
							cin >> player2Salary;
							cout << player2 << ", salary: " << player2Salary << endl;

							userPlayer = 1;
						}
					}
					else if (userResponse == "pay")
					{
						cout << "You landed on a payday space." << endl;
						cout << "If you already have your job, please state what your job is." << endl;
						cout << "If you don't have a job yet, enter 'continue'." << endl;
						cin >> userResponse;

						if (userResponse == "lawyer" || "Lawyer")
						{
							cout << "Take your salary and an additional 100k bonus." << endl;
							cout << "The bank owes you " << player2Salary << endl;

							player2Storage += player2Salary;

							cout << "Current money: " << player2Salary << endl;

							userPlayer = 1;
						}
						else if (userResponse == "doctor" || "Doctor")
						{
							cout << "Take your salary and an additional 100k bonus." << endl;
							cout << "The bank owes you " << player2Salary << endl;

							player2Storage += player2Salary;

							cout << "Current money: " << player2Salary << endl;

							userPlayer = 1;
						}
						else if (userResponse == "video-game")
						{
							cout << "Take your salary and an additional 100k bonus." << endl;
							cout << "The bank owes you " << player2Salary << endl;

							player2Storage += player2Salary;

							cout << "Current money: " << player2Salary << endl;

							userPlayer = 1;
						}
						else if (userResponse == "secret-agent")
						{
							cout << "Take your salary and an additional 100k bonus." << endl;
							cout << "The bank owes you " << player2Salary << endl;

							player2Storage += player2Salary;

							cout << "Current money: " << player2Salary << endl;

							userPlayer = 1;
						}
						else if (userResponse == "teacher" || "Teacher")
						{
							cout << "Take your salary and an additional 100k bonus." << endl;
							cout << "The bank owes you " << player2Salary << endl;

							player2Storage += player2Salary;

							cout << "Current money: " << player2Salary << endl;

							userPlayer = 1;
						}
						else if (userResponse == "scientist" || "Scientist")
						{
							cout << "Take your salary and an additional 100k bonus." << endl;
							cout << "The bank owes you " << player2Salary << endl;

							player2Storage += player2Salary;

							cout << "Current money: " << player2Salary << endl;

							userPlayer = 1;
						}
						else if (userResponse == "vet" || "Vet")
						{
							cout << "Take your salary and an additional 100k bonus." << endl;
							cout << "The bank owes you " << player2Salary << endl;

							player2Storage += player2Salary;

							cout << "Current money: " << player2Salary << endl;

							userPlayer = 1;
						}
						else if (userResponse == "fashion-designer")
						{
							cout << "Take your salary and an additional 100k bonus." << endl;
							cout << "The bank owes you " << player2Salary << endl;

							player2Storage += player2Salary;

							cout << "Current money: " << player2Salary << endl;

							userPlayer = 1;
						}
						else if (userResponse == "continue")
						{
							cout << "Firstly, you need your new job." << endl;
							cout << "Enter 'draw' for your new job." << endl;
							cin >> userResponse;

							if (userResponse == "draw" || "Draw")
							{
								CollegeCareer randCareer;
								randCareer.CollegeCareerCards();

								cout << "What is your salary?" << endl;
								cin >> player2Salary;
								cout << player2 << ", salary: " << player2Salary << endl;
								cout << "What is your job?" << endl;
								cin >> userResponse;
							}
							if (userResponse == "lawyer" || "Lawyer")
							{
								cout << "Take your salary and an additional 100k bonus." << endl;
								cout << "The bank owes you " << player2Salary << endl;

								player2Storage += player2Salary;

								cout << "Current money: " << player2Salary << endl;

								userPlayer = 1;
							}
							else if (userResponse == "doctor" || "Doctor")
							{
								cout << "Take your salary and an additional 100k bonus." << endl;
								cout << "The bank owes you " << player2Salary << endl;

								player2Storage += player2Salary;

								cout << "Current money: " << player2Salary << endl;

								userPlayer = 1;
							}
							else if (userResponse == "video-game")
							{
								cout << "Take your salary and an additional 100k bonus." << endl;
								cout << "The bank owes you " << player2Salary << endl;

								player2Storage += player2Salary;

								cout << "Current money: " << player2Salary << endl;

								userPlayer = 1;
							}
							else if (userResponse == "secret-agent")
							{
								cout << "Take your salary and an additional 100k bonus." << endl;
								cout << "The bank owes you " << player2Salary << endl;

								player2Storage += player2Salary;

								cout << "Current money: " << player2Salary << endl;

								userPlayer = 1;
							}
							else if (userResponse == "teacher" || "Teacher")
							{
								cout << "Take your salary and an additional 100k bonus." << endl;
								cout << "The bank owes you " << player2Salary << endl;

								player2Storage += player2Salary;

								cout << "Current money: " << player2Salary << endl;

								userPlayer = 1;
							}
							else if (userResponse == "scientist" || "Scientist")
							{
								cout << "Take your salary and an additional 100k bonus." << endl;
								cout << "The bank owes you " << player2Salary << endl;

								player2Storage += player2Salary;

								cout << "Current money: " << player2Salary << endl;

								userPlayer = 1;
							}
							else if (userResponse == "vet" || "Vet")
							{
								cout << "Take your salary and an additional 100k bonus." << endl;
								cout << "The bank owes you " << player2Salary << endl;

								player2Storage += player2Salary;

								cout << "Current money: " << player2Salary << endl;

								userPlayer = 1;
							}
							else if (userResponse == "fashion-designer")
							{
								cout << "Take your salary and an additional 100k bonus." << endl;
								cout << "The bank owes you " << player2Salary << endl;

								player2Storage += player2Salary;

								cout << "Current money: " << player2Salary << endl;

								userPlayer = 1;
							}
						}
					}
					else if (userResponse == "win")
					{
						cout << "Who landed on the spin-to-win space?" << endl;
						cin >> userResponse;

						if (userResponse == "player1")
						{
							cout << player1 << ", choose two numbers on the wheel you think you have a chance of spinning and memorize them." << endl;
							cout << endl;
							cout << player2 << ", choose one number on the wheel you think yo have a chance of spinning and memorize it." << endl;
							cout << player1 << ", 'spin' the wheel until one of the numbers is landed upon." << endl;
							cin >> userResponse;

							if (userResponse == "spin" || "Spin")
							{
								srand(time(0));
								for (int i = 0; i < 1; ++i)
								{
									Spinner SpinTheWheelOfFortune;
									SpinTheWheelOfFortune.randomSpin();

									cout << "If you landed on one of the nubmers, enter 'c' to move on." << endl;
									cout << "If you did not land on one of the numbers, enter 's' to keep spinning." << endl;
									cin >> userResponseSub2;

									if (userResponseSub2 == 'c')
									{
										cout << "Whose number was chosen? (player 1 or player 2)" << endl;
										cin >> userResponse;

										if (userResponse == "player1")
										{
											cout << player1 << " gets 200k" << endl;

											player1Storage += 200000;

											cout << player1 << ", current balance: " << player1Storage << endl;
											cout << player1 << ", current position: " << player1Position << endl;

											userPlayer = 1;
										}
										else if (userResponse == "player2")
										{
											cout << player2 << " gets 200k" << endl;

											player2Storage += 200000;

											cout << player2 << ", current balance: " << player1Storage << endl;

											userPlayer = 1;
										}
									}
									else if (userResponseSub2 == 's')
									{
										continue; // Ignore and continue.
									}
								}
							}
						}
						else if (userResponse == "player2")
						{
							cout << player2 << ", choose two numbers on the wheel you think you have a chance of spinning and memorize them." << endl;
							cout << endl;
							cout << player1 << ", choose one number on the wheel you think yo have a chance of spinning and memorize it." << endl;
							cout << player2 << ", 'spin' the wheel until one of the numbers is landed upon." << endl;
							cin >> userResponse;

							if (userResponse == "spin" || "Spin")
							{
								srand(time(0));
								for (int i = 0; i < 1; ++i)
								{
									Spinner SpinTheWheelOfFortune;
									SpinTheWheelOfFortune.randomSpin();
									cout << "If you landed on one of the nubmers, enter 'c' to move on." << endl;
									cout << "If you did not land on one of the numbers, enter 's' to keep spinning." << endl;
									cin >> userResponseSub2;

									if (userResponseSub2 == 'c')
									{
										cout << "Whose number was chosen? (player 1 or player 2)" << endl;
										cin >> userResponse;

										if (userResponse == "player2")
										{
											cout << player2 << " gets 200k" << endl;

											player2Storage += 200000;

											cout << player2 << ", current balance: " << player2Storage << endl;
											cout << player2 << ", current position: " << player2Position << endl;

											userPlayer = 1;
										}
										else if (userResponse == "player1")
										{
											cout << player1 << " gets 200k" << endl;

											player1Storage += 200000;

											cout << player1 << ", current balance: " << player1Storage << endl;

											userPlayer = 1;
										}
									}
									else if (userResponseSub2 == 's')
									{
										continue;
									}
								}
							}
						}
					}
				}
			}
		}
		if ((player1Position == 10) && (userPlayer == 2)) // Conditional statements to determine end of game based on user position.
		{
			cout << player1 << ", you have reached retirement!" << endl;
		}
		if ((player2Position == 10) && (userPlayer == 1))
		{
			cout << player2 << ", you have reached retirement!" << endl;
		}

		cout << player1 << " and " << player2 << ", please add up all of your money." << endl;
		cout << "Enter 'c' to use the built in calculator." << endl;
		cout << player1 << ", go first." << endl;
		cout << player1 << ", current balance: " << player1Storage << endl;

		cin >> userResponseSub2;

		if (userResponseSub2 == 'c') // Calculator function so that players can add up their money.
		{
			char mthOperator;
			float num1, num2;

			cout << "Enter operator either + or - or * or /";
			cin >> mthOperator;

			cout << "Enter two operands: ";
			cin >> num1 >> num2;

			switch (mthOperator) // Switch statement works through all basic math operators that don't require an imported library.
			{
			case '+':
				cout << num1 + num2;
				break;

			case '-':
				cout << num1 - num2;
				break;

			case '*':
				cout << num1 * num2;
				break;

			case '/':
				cout << num1 / num2;
				break;

			default:
				cout << "Incorrect operator.";
				break;
			}
		}

		cout << player2 << ", add up all your moeny." << endl;
		cout << player2 << ", current balance: " << player2Storage << endl;
		cout << "Enter 'c' to use the built in calculator." << endl;

		cin >> userResponseSub2;

		if (userResponseSub2 == 'c')
		{
			char mthOperator;
			float num1, num2;

			cout << "Enter operator either + or - or * or /";
			cin >> mthOperator;

			cout << "Enter two operands: ";
			cin >> num1 >> num2;

			switch (mthOperator)
			{
			case '+':
				cout << num1 + num2;
				break;

			case '-':
				cout << num1 - num2;
				break;

			case '*':
				cout << num1 * num2;
				break;

			case '/':
				cout << num1 / num2;
				break;

			default:
				cout << "Incorrect operator.";
				break;
			}
		}

		cout << "Who had the most money? (player1 or player2)" << endl;
		cin >> userResponse;

		if (userResponse == "player1")
		{
			cout << player1 << " wins!!" << endl;
		}
		else if (userResponse == "player2")
		{
			cout << player2 << " wins!!" << endl;
		}

		cout << "Do you want to play again." << endl;
		cout << "Enter 'y' for yes and 'n' for no." << endl;
		cin >> userResponseSub2;

		if (userResponseSub2 == 'y') // Play again functionality.
		{
			continue;
		}
		else if (userResponseSub2 == 'n')
		{
			break;
		}
	}
}