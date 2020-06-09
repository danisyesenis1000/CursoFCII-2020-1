#include "Automaton.h"

Automaton::Automaton(){
    Set_dim(0);
    Set_rule(0);
    M = NULL;
    Dicc = Alloc_Int(8, 4, 3);
    Full(Dicc);
    srand(time(NULL));
}


// ==================================================================================================
// ==================== DEFINE ======================================================================
// ==================================================================================================
void Automaton::Set_dim(int d){
  dim = d;
}

void Automaton::Set_rule(int r){
  rule = r;
}

// ==================================================================================================
// ==================== PRINT =======================================================================
// ==================================================================================================
// Print a matrix
void Automaton::Print(int rows, int columns, int **M){
    for(int i1 = 0; i1 < rows; i1++){
        for(int i2 = 0; i2 < columns; i2++){
            cout << M[i1][i2] << "  ";
        }

        cout << endl;
    }
}

void Automaton::Print(int n, int  *A){
    for(int i1 = 0; i1 < n; i1++)
        cout << *(A + i1) << " ";
    cout << endl;
}

void Automaton::Print(int n, double  *A){
    for(int i1 = 0; i1 < n; i1++)
        cout << *(A + i1) << " ";
    cout << endl;
}

// Print an array in a file
void Automaton::Print_File(string name, int l, double *X, int accuracy){
    fstream file_out(name.c_str(),ios::out);
    if(file_out.fail()){
        cout << "Fail trying to open the file" << endl;
        exit(1);
    }

    for(int i = 0; i < l; i++){
        file_out << left << fixed << setprecision(accuracy) << setw(accuracy) << *(X + i)  << endl;
    }

    file_out.close();
}

// Print a matrix in a file, the file is saved without format, that is, the
// file contains multiples lines but only one column, you have to pay attention to read
void Automaton::Print_File(string nombre, int n1, int n2, int **conjunta){
    fstream archivo_sal(nombre.c_str(), ios::out);
    if(archivo_sal.fail()){
        cout << "Fail trying to open the file" << endl;
        exit(1);
    }

    for(int i5 = 0; i5 < n1; i5++){
        for(int i6 = 0; i6 < n2; i6++){
            archivo_sal << left  << setw(1) << conjunta[i5][i6] << endl;
        }
    }

    archivo_sal.close();
}

// ===============================================================================================================
double* Automaton::Linspace(double ini, double end, int n_points){
    double *Vector = (double *) malloc((size_t) sizeof(double) * n_points);
    double step = (double) (end - ini) / n_points;

    for(int i6=0;i6<n_points;i6++)
        *(Vector + i6) = ini + step * i6;

    return Vector;
}

// ================================================================================================================
int **Automaton::Alloc_Int(int rows,int columns,int mode){
    int **M = (int **) malloc((size_t) sizeof(int *) * rows);

    for(int i = 0; i < rows; i++)
        *(M+i) = (int *) malloc((size_t) sizeof(int) * columns);

    // Ising mode to spin 1/2
    if(mode == 0){
        for(int i1 = 0; i1 < rows; i1++){
	        for(int i2 = 0; i2 < columns; i2++){
	            M[i1][i2] = pow(-1, 1 + rand() % 2);
	        }
	    }
    } else if(mode == 1){
        // Heisenberg mode spin 3/2
        int h;
        for(int i1 = 0; i1 < rows; i1++){
        	for(int i2 = 0; i2 < columns; i2++){
	            h = 1 + rand() % 2;
	            M[i1][i2] = h * pow(-1, 1 + rand() % 2);
	        }
	    }
    } else if(mode == 2){
        // Classic Heisenberg
        for(int i1 = 0; i1 < rows; i1++){
	        for(int i2 = 0; i2 < columns; i2++){
	            M[i1][i2] = rand() % 255;
	        }
	    }
    }else if(mode == 3){
        for(int i1 = 0; i1 < rows; i1++){
	        for(int i2 = 0; i2 < columns; i2++){
	            M[i1][i2] = 0;
	        }
	    }
    }

    return M;
}

//==========================================================================
void Automaton::To_Binary(int num, int *b){
    int i = 7;
    float m;
    int l = num*0.5;

    while(l != 0){
        *(b + i) = num % 2;
        m = (float) num * 0.5;
        num = (int) m;
        i--;
        l = num*0.5;
    }

    *(b + i) = num;
}

// ==========================================================================
// Full with all the possibilities with three bits
void Automaton::Full(int **D){
    int c1;
    for(int i1 = 0; i1 < 8; i1++){
        if(i1 < 4)
            c1 = 1;
        else
            c1 = 0;

        for(int i2 = 0; i2 < 3; i2++){
            if(i2 == 0)
                D[i1][i2] = c1;

            if(i2 == 1)
                D[i1][i2] = ((i1 + 2) / 2) % 2;

            if(i2 == 2)
                D[i1][i2] = (i1 + 1) % 2;
        }
    }
}

// wlak trhough every box and take a decision using the Diccionary (Dicc)
void Automaton::Evolution(int total, int row, int **M, int **Dicc){
    int state1, state2, state3, decision;

    for(int j = 0; j < total; j++){
        // periodic boundaries
        if(j == 0){
            state1=M[row][total - 1];
            state2=M[row][j];
            state3=M[row][j + 1];
        } else if(j == total - 1){
            // periodic boundaries
            state1=M[row][j - 1];                  
            state2=M[row][j];
            state3=M[row][0];
        } else {
            state1=M[row][j - 1];
            state2=M[row][j];
            state3=M[row][j + 1];
        }

        for(int k = 0; k < 8; k++){
            if(state1 == Dicc[k][0] && state2 == Dicc[k][1] && state3 == Dicc[k][2]){
                decision = Dicc[k][3];
                break;
            }
        }

        M[row+1][j] = decision;
    }
}

void Automaton::Automaton_1D(){
    cout << "Welcome to the automaton" << endl;
    cout << "insert the rule that you want to simulate: ";
    int j;
    int c = 0;

    do {
        if(c != 0){
            cout << "rule out of range, remember that the possible rules are between 0 and 255, try again" << endl;
            cout << "insert the rule that you want to simulate: ";
        }
        cin >> j;  
        c++;
    } while(j < 0 || j > 256);
    
    Set_rule(j);
    cout << "how many cells do you want? : ";
    cin >> j;  // columns
    cout << "how many steps do you want? : ";
    cin >> c;  // rows
    
    int binary[8] = {0};
    // Alloc matrix with c rows and j columns and initializated in mode 3 (full of zeros)
    M = Alloc_Int(c, j, 3);
    To_Binary(rule, binary);

    for(int i = 0; i < 8; i++)
        Dicc[i][3] = binary[i];
    // Print(8, 4, Dicc);

    cout << "Do you want to enter the initial condition or do you prefer take it randomly?" << endl;
    cout << "press 1 for entering the initial condition or 0 for taking it randomly : ";
    int d;
    int c1 = 0;
    do {
        if(c1!=0){
            cout << "value out of range, remember that the possible values are between 0 and 1, try again" << endl;
            cout << "press 1 for entering the initial condition or 0 for taking it randomly : ";
        }

        cin >> d;  
        c1++;
    } while(d != 0 && d != 1);

    if(d == 0){
        double r;

        for(int i = 0; i < j; i++){
            r = (double) rand() / RAND_MAX;
            if(r >= 0.5)
                M[0][i] = 1;

            if(r < 0.5)
                M[0][i] = 0;
        }
    }

    if(d == 1){
        cout << "enter every value of the " << j << " values in total"<< endl;
        for(int f = 0; f < j; f++){
            cin >> M[0][f];
        }
    }

    for(int h = 0; h < c - 1; h++){
        Evolution(j, h, M, Dicc);
    }

    // Print(c, j, M);
    Print_File("matrix.txt", c, j, M);
}

void Automaton::Automaton_1D(int r, int j, int c, int *I_C){
    Set_rule(r);
    int binary[8] = {0};
    M = Alloc_Int(c, j, 3);
    To_Binary(rule, binary);

    for(int i = 0; i < 8; i++)
        Dicc[i][3] = binary[i];
    
    // Print(8, 4, Dicc);
    for(int i = 0; i < j; i++){
        M[0][i] = I_C[i];
    }
    
    for(int h = 0; h < c - 1; h++){
        Evolution(j, h, M, Dicc);
    }

    // Print(c,j,M);
    Print_File("matrix.txt", c, j, M);
}

// ================================================================================================================================
// ============================================= ISING MODEL FOR MAGNETISM ========================================================
// ================================================================================================================================
int Automaton::Magnetization(int rows, int columns,int **M){
    int m = 0;
    for(int i1 = 0; i1 < rows; i1++){
        for(int i2 = 0; i2 < columns; i2++)
            m += M[i1][i2];
    }

    return m;
}

// for calculing the energy I need the matrix, I need J, the external magnetic field and the nucleon or atom position.
double Automaton::Spin_Energy(double J, double H, int i, int j, int N, int **M){
    int s2, s3, s4, s5, mi;
    double E_plus,E_minus,delta_E;

    if(i!=0 && j!=0){
        s2=M[i+1][j];   // neighbor 1
        s3=M[i][j+1];   // neighbor 2
        s4=M[i-1][j];   // neighbor 3
        s5=M[i][j-1];   // neighbor 4
    } else{
        if(i == 0 && j != 0){
            s2=M[i+1][j];   // neighbor 1
            s3=M[i][j+1];   // neighbor 2
            s4=M[N-1][j];   // neighbor 3
            s5=M[i][j-1];   // neighbor 4
        } else if(i != 0 && j == 0) {
            s2=M[i+1][j];   // neighbor 1
            s3=M[i][j+1];   // neighbor 2
            s4=M[i-1][j];   // neighbor 3
            s5=M[i][N-1];   // neighbor 4
        } else if(i == 0 && j == 0) {
            s2=M[i+1][j];   // neighbor 1
            s3=M[i][j+1];   // neighbor 2
            s4=M[N-1][j];   // neighbor 3
            s5=M[i][N-1];   // neighbor 4
        }
    }

    mi = s2 + s3 + s4 + s5;     // sum the four neighbors        
    E_plus = (double) -(J * mi) - H;
    E_minus = (double) (J * mi) + H;
    delta_E = (E_plus - E_minus);

    return delta_E;
}

double Automaton::Magnetization_Graph(int SIZE, int mode, double J, double H, int iterations, double b){
    M = Alloc_Int(SIZE, SIZE, mode);
    // Print(SIZE, SIZE, M);
    int x, y;
    double p_up, p_down, random, DE;

    for(int i8 = 0; i8 < iterations; i8++){
        // gereting a random position in the grid
        x = rand() % (SIZE - 1);                              
        y = rand() % (SIZE - 1);
        DE = (double) Spin_Energy(J, H, x, y, SIZE, M);
        p_up= (double) 1.0 / (1.0 + pow(M_E, b * DE));
        p_down= (double) 1.0 / (1.0 + pow(M_E, -b * DE));
        random = (double) rand() / RAND_MAX;

        if(p_up <= p_down){
            if(random < p_up)
                M[x][y] = 1;
            else
                M[x][y] = -1;
        } else{
            if(random < p_down)
                M[x][y] = -1;
            else
                M[x][y] = 1;
        }
    }

    double mag = (double) Magnetization(SIZE, SIZE, M);
    double total = (double) SIZE;
    return mag / (total * total);
}

Automaton::~Automaton(){
    cout << endl;
    for(int i = 0; i < 8; i++)
        free(Dicc[i]);
}
