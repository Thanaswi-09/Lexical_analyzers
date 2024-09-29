#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
// Enum for token types
typedef enum {
 IDENTIFIER,
 ASSIGN_OP,
 INT_LITERAL,
 ADD_OP,
 SEMICOLON
} TokenType;
// Structure for a token
typedef struct {
 TokenType type;
 char value[50]; // Assuming a maximum token length of 50 characters
} Token;
// Function to get the next token from the input string
Token getNextToken(char *input) {
 Token token;
 // Skip whitespaces
while (isspace(*input)) {
 input++;
 }
 // Check for the end of the input
 if (*input == '\0') {
 token.type = SEMICOLON; // Assume end of statement at the end of input
 strcpy(token.value, "");
 return token;
 }
 // Check for identifier
 if (isalpha(*input)) {
 token.type = IDENTIFIER;
 sscanf(input, "%s", token.value);
 }
 // Check for assignment operator
 else if (*input == '=') {
 token.type = ASSIGN_OP;
 token.value[0] = '=';
 token.value[1] = '\0';
 input++;
 }
 // Check for integer literal
 else if (isdigit(*input)) {
 token.type = INT_LITERAL;
sscanf(input, "%s", token.value);
 }
 // Check for addition operator
 else if (*input == '+') {
 token.type = ADD_OP;
 token.value[0] = '+';
 token.value[1] = '\0';
 input++;
 }
 // Check for semicolon
 else if (*input == ';') {
 token.type = SEMICOLON;
 token.value[0] = ';';
 token.value[1] = '\0';
 input++;
 }
 // Handle unknown characters
 else {
 fprintf(stderr, "Error: Unknown character '%c'\n", *input);
 exit(EXIT_FAILURE);
 }
 return token;
}
int main() {
char input[] = "sum = 3+2;";
 Token token;
 printf("Token\t\tToken Type\n");
 do {
 token = getNextToken(input);
 // Print token information
 printf("%-15s\t", token.value);
 switch (token.type) {
 case IDENTIFIER:
 printf("Identifier\n");
 break;
 case ASSIGN_OP:
 printf("Assignment Operator\n");
 break;
 case INT_LITERAL:
 printf("Integer Literal\n");
 break;
 case ADD_OP:
 printf("Addition Operator\n");
 break;
 case SEMICOLON:
 printf("End of Statement\n");
break;
 default:
 fprintf(stderr, "Error: Unknown token type\n");
 exit(EXIT_FAILURE);
 }
 // Move to the next token
 input += strlen(token.value);
 } while (token.type != SEMICOLON);
 return 0;
}
