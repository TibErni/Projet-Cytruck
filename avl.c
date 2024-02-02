#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <assert.h>

typedef struct Route Route_t;
struct Route {
    int routeID;
    int stepID;
    char townA[50];
    char townB[50];
    int distance;
    char driverName[50];
};

struct avl_node_s {
	struct avl_node_s *left;
	struct avl_node_s *right;
	Route_t *value;
};

typedef struct avl_node_s avl_node_t;

struct avl_tree_s {
	struct avl_node_s *root;
};

typedef struct avl_tree_s avl_tree_t;


/* Create a new AVL tree. */
avl_tree_t *avl_create() {
	avl_tree_t *tree = NULL;

	if( ( tree = malloc( sizeof( avl_tree_t ) ) ) == NULL ) {
		return NULL;
	}

	tree->root = NULL;

	return tree;
}

/* Initialize a new node. */
avl_node_t *avl_create_node() {
	avl_node_t *node = NULL;
	
	if( ( node = malloc( sizeof( avl_node_t ) ) ) == NULL ) {
		return NULL;
	}

	node->left = NULL;
	node->right = NULL;
	node->value = malloc( sizeof(Route_t) );

	return node;	
}

/* Find the height of an AVL node recursively */
int avl_node_height( avl_node_t *node ) {
	int height_left = 0;
	int height_right = 0;

	if( node->left ) height_left = avl_node_height( node->left );
	if( node->right ) height_right = avl_node_height( node->right );

	return height_right > height_left ? ++height_right : ++height_left;
}

/* Find the balance of an AVL node */
int avl_balance_factor( avl_node_t *node ) {
	int bf = 0;

	if( node->left  ) bf += avl_node_height( node->left );
	if( node->right ) bf -= avl_node_height( node->right );

	return bf ;
}

/* Left Left Rotate */
avl_node_t *avl_rotate_leftleft( avl_node_t *node ) {
 	avl_node_t *a = node;
	avl_node_t *b = a->left;
	
	a->left = b->right;
	b->right = a;

	return( b );
}

/* Left Right Rotate */
avl_node_t *avl_rotate_leftright( avl_node_t *node ) {
	avl_node_t *a = node;
	avl_node_t *b = a->left;
	avl_node_t *c = b->right;
	
	a->left = c->right;
	b->right = c->left; 
	c->left = b;
	c->right = a;

	return( c );
}

/* Right Left Rotate */
avl_node_t *avl_rotate_rightleft( avl_node_t *node ) {
	avl_node_t *a = node;
	avl_node_t *b = a->right;
	avl_node_t *c = b->left;
	
	a->right = c->left;
	b->left = c->right; 
	c->right = b;
	c->left = a;

	return( c );
}

/* Right Right Rotate */
avl_node_t *avl_rotate_rightright( avl_node_t *node ) {
	avl_node_t *a = node;
	avl_node_t *b = a->right;
	
	a->right = b->left;
	b->left = a; 

	return( b );
}

/* Balance a given node */
avl_node_t *avl_balance_node( avl_node_t *node ) {
	avl_node_t *newroot = NULL;

	/* Balance our children, if they exist. */
	if( node->left )
		node->left  = avl_balance_node( node->left  );
	if( node->right ) 
		node->right = avl_balance_node( node->right );

	int bf = avl_balance_factor( node );

	if( bf >= 2 ) {
		/* Left Heavy */	

		if( avl_balance_factor( node->left ) <= -1 ) 
			newroot = avl_rotate_leftright( node );
		else 
			newroot = avl_rotate_leftleft( node );

	} else if( bf <= -2 ) {
		/* Right Heavy */

		if( avl_balance_factor( node->right ) >= 1 )
			newroot = avl_rotate_rightleft( node );
		else 
			newroot = avl_rotate_rightright( node );

	} else {
		/* This node is balanced -- no change. */

		newroot = node;
	}

	return( newroot );	
}

/* Balance a given tree */
void avl_balance( avl_tree_t *tree ) {

	avl_node_t *newroot = NULL;

	newroot = avl_balance_node( tree->root );

	if( newroot != tree->root )  {
		tree->root = newroot; 
	}
}

/* Insert a new node. */
void avl_insert( avl_tree_t *tree, Route_t *value ) {
	avl_node_t *node = NULL;
	avl_node_t *next = NULL;
	avl_node_t *last = NULL;

	/* Well, there must be a first case */ 	
	if( tree->root == NULL ) {
		node = avl_create_node();
		node->value = value;

		tree->root = node;

	/* Okay.  We have a root already.  Where do we put this? */
	} else {
		next = tree->root;

		while( next != NULL ) {
			last = next;

            if (value->distance < next->value->distance) {
                next = next->left;
            } else if (value->distance > next->value->distance) {
                next = next->right;
            } else {
                return;
            }
		}

		node = avl_create_node();
		node->value = value;

        if (value->distance < last->value->distance) {
            last->left = node;
        } else if (value->distance > last->value->distance) {
            last->right = node;
        }
		
	}

	avl_balance( tree );
}

/* Find the node containing a given value */
avl_node_t *avl_find( avl_tree_t *tree, Route_t* value ) {
	avl_node_t *current = tree->root;

    while (current && (current->value->distance != value->distance)) {
        if (value > current->value)
			current = current->right;
		else
			current = current->left;
	}
	return current;
}

/* Do a depth first traverse of a node. */
void avl_traverse_node_dfs( avl_node_t *node, int depth ) {
	int i = 0;

	if( node->left ) avl_traverse_node_dfs( node->left, depth + 2 );

	for( i = 0; i < depth; i++ ) putchar( ' ' );
	printf( "%s: %d\n", node->value, avl_balance_factor( node ) );

	if( node->right ) avl_traverse_node_dfs( node->right, depth + 2 );
}

/* Do a depth first traverse of a tree. */
void avl_traverse_dfs( avl_tree_t *tree ) {
	avl_traverse_node_dfs( tree->root, 0 );
}

void avl_print_node( avl_node_t *node, char* fmt) {
    int i = 0;

    if( node->left ) avl_print_node( node->left, fmt);

    printf( fmt, node->value->routeID, node->value->stepID, node->value->townA, node->value->townB, node->value->distance, node->value->driverName);

    if( node->right ) avl_print_node( node->right, fmt);
}

void avl_print( avl_tree_t *tree, char* fmt) {
    avl_print_node( tree->root, fmt);
}

void avl_count_node( avl_node_t *node, int* res ) {
	if( node->left ) avl_count_node( node->left, res);
	*res = *res+1;
	if( node->right ) avl_count_node( node->right, res);
}

void avl_count(avl_tree_t *tree, int* res) {
	avl_count_node(tree->root, res);
}

void avl_free( avl_node_t *node ) {
	if( node->left ) avl_free( node->left );
	if( node->right ) avl_free( node->right );

	free( node );
}

// Create Hash table to store the number of times a town appears
typedef struct HashItem {
    char *key;
    int count;
    int routeID; // Route ID of the route that contains the town
} HashItem_t;

typedef struct HashTable {
    int size;
    int count;
    HashItem_t **array;
} HashTable_t;

HashTable_t *createHashTable(int size) {
    HashTable_t *table = malloc(sizeof(HashTable_t));
    table->size = size;
    table->count = 0;
    table->array = malloc(sizeof(HashItem_t *) * size);
    for (int i = 0; i < size; i++) {
        table->array[i] = NULL;
    }
    return table;
}

int hashCode(HashTable_t *table, char *key) {
    int hash = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        hash += key[i];
    }
    return hash % table->size;
}

void hashInsert(HashTable_t *table, char *key, int routeID) {
    int index = hashCode(table, key);
    while (table->array[index] != NULL && strcmp(table->array[index]->key, key) != 0 && routeID != table->array[index]->routeID) {
        index++;
        index %= table->size;
    }

    if (table->array[index] == NULL) {
        // Insert new item
        table->array[index] = malloc(sizeof(HashItem_t));
        table->array[index]->key = strdup(key); // Make a copy of the key
        table->array[index]->count = 1;
    } else {
        // Key already exists, increment the count
        table->array[index]->count++;
    }
}

int hashCount(HashTable_t *table, char *key) {
    // We count the towns by their name, so we need to find the town with the same name
	int index = hashCode(table, key);
	while (table->array[index] != NULL && strcmp(table->array[index]->key, key) != 0) {
		index++;
		index %= table->size;
	}

	if (table->array[index] == NULL) {
		// Key not found
		return 0;
	} else {
		// Key found, return the count
		return table->array[index]->count;
	}
}

void hashPrint(HashTable_t *table) {
    for (int i = 0; i < table->size; i++) {
        if (table->array[i] != NULL) {
            printf("%s : %d\n", table->array[i]->key, table->array[i]->count);
        }
    }
}

void hashFree(HashTable_t *table) {
    for (int i = 0; i < table->size; i++) {
        if (table->array[i] != NULL) {
            free(table->array[i]->key);
            free(table->array[i]);
        }
    }
    free(table->array);
    free(table);
}

int compareHashItems(const void *a, const void *b) {
    HashItem_t *item1 = *(HashItem_t **)a;
    HashItem_t *item2 = *(HashItem_t **)b;

	return item2->count - item1->count;
}

void hashSaveInTxt(HashTable_t *table) {
    FILE *fp = fopen("./results.txt", "w");
	int count = 0;
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(EXIT_FAILURE);
    }

	// Sort the array by count
	qsort(table->array, table->count, sizeof(HashItem_t *), compareHashItems);

	// Print the array to file
	for (int i = 0; i < table->size; i++) {
		if (table->array[i] != NULL) {
			fprintf(fp, "%s;%d\n", table->array[i]->key, table->array[i]->count);
			count++;
		}

		if (count == 10) {
			break;
		}
	}

    fclose(fp);
}

void addTown(HashTable_t *table, char *town, int routeID) {
    hashInsert(table, town, routeID);
}

void avl_traverse_and_count(avl_node_t *node, HashTable_t *table) {
    if (node->left) avl_traverse_and_count(node->left, table);
    addTown(table, node->value->townA, node->value->routeID);
    addTown(table, node->value->townB, node->value->routeID);
    if (node->right) avl_traverse_and_count(node->right, table);
}

int main( int argc, char **argv ) {
	avl_tree_t *tree = NULL;

	tree = avl_create();

	// Read data2.csv and insert into tree
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen("./data.csv", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(EXIT_FAILURE);
    }

    // Skip first line
    getline(&line, &len, fp);

    while ((read = getline(&line, &len, fp)) != -1) {
        Route_t *route = malloc(sizeof(Route_t));
        char *token = strtok(line, ";");
        route->routeID = atoi(token);
        token = strtok(NULL, ";");
        route->stepID = atoi(token);
        token = strtok(NULL, ";");
        strcpy(route->townA, token);
        token = strtok(NULL, ";");
        strcpy(route->townB, token);
        token = strtok(NULL, ";");
        route->distance = atoi(token);
        token = strtok(NULL, ";");
        strcpy(route->driverName, token);
        avl_insert(tree, route);
    }

    fclose(fp);

    // avl_print(tree, "%d,%d,%s,%s,%d,%s");

    struct HashTable *table = createHashTable(35000);
	avl_traverse_and_count(tree->root, table);
	// hashPrint(table);
	hashSaveInTxt(table);

	hashFree(table);
	avl_free(tree->root);

	return 0;
}