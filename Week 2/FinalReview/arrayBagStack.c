

void initArray(struct arrayBagStack* b){
    // Validate params
    assert(b != 0);

    data = malloc(sizeof(TYPE) * 100);
    count = 0;
}


void pushArray(struct arrayBagStack* b, int v){
    // Validate params
    assert(b != 0);

    addArray(b, v);
}

TYPE topArray(struct arrayBagStack* b){
    // Validate params
    assert(b != 0);

    return b->data[0];
}

void popArray(struct arrayBagStack* b){
    assert(b != 0);

    if( b->count > 0){
        b->count--;
        for(int i = 0; i < b->count; i++){
            b->data[i] = b->data[i + 1];
        }
    }
}

int isEmptyArray(struct arrayBagStack* b){
    assert(b != 0);

    if(b->count == 0){
        return 1;
    }
    else{
        return 0;
    }
}

void addArray(struct arrayBagStack* b, int v){
    assert(b != 0);

    if( b->count < 100 ){
        b->data[count] = v;
    }
}

int containsArray(struct arrayBagStack* b, int v){

    int isFound = 0;
    int currentIndex = 0;
    while( (!isFound) && (currentIndex < b->count) ){
        if(b->data[currentIndex] == v){
            isFound = 1;
        }
        currentIndex++;
    }

    if(isFound == 1){
        return 1;
    }
    else{
        return 0;
    }
}

void removeArray(struct arrayBagStack* b, int v){
    int isFound = 0;
    int currentIndex = 0;
    while( (!isFound) && (currentIndex < b->count) ){
        if(b->data[currentIndex] == v){
            isFound = 1;
        }
        currentIndex++;
    }

    if(isFound == 1){
        b->count--;
        for(currentIndex; currentIndex < b->count; currentIndex++){
            b->data[currentIndex] = b->data[currentIndex + 1];
        }
    }
}

int sizeArray(struct arrayBagStack* b){
    return b->count;
}

initDynArr(struct DynArr *v, int capacity){
    v->data = malloc(sizeof(TYPE) * capacity);
    v->size = 0;
    v->capacity = capacity;
}

void _setCapacityDynArr(struct DynArr *v, int newCap){
    struct DynArr *newArray;

    initDynArr(&newArray, newCap);

    for(int i = 0; i < v->size; i++){
        newArray->data[i] = v->data[i];
    }

    freeDynArray(v);

    v = newArray;
}
