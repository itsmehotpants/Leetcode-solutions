const long long MOD = 1e9 + 7;

// Struct to represent a square matrix for matrix exponentiation
struct Matrix {
    std::vector<std::vector<long long>> mat;
    int dim; // Dimension of the square matrix (dim x dim)

    // Constructor
    Matrix(int d) : dim(d) {
        mat.resize(dim, std::vector<long long>(dim, 0));
    }

    // Static method to create an identity matrix
    static Matrix identity(int d) {
        Matrix I(d);
        for (int i = 0; i < d; ++i) {
            I.mat[i][i] = 1;
        }
        return I;
    }

    // Overload the multiplication operator for Matrix * Matrix
    Matrix operator*(const Matrix& other) const {
        Matrix result(dim);
        for (int i = 0; i < dim; ++i) {
            for (int j = 0; j < dim; ++j) {
                for (int k = 0; k < dim; ++k) {
                    result.mat[i][j] = (result.mat[i][j] + mat[i][k] * other.mat[k][j]) % MOD;
                }
            }
        }
        return result;
    }
};

// Function for matrix exponentiation (Matrix ^ power) using binary exponentiation
Matrix matrix_pow(Matrix base, long long exp) {
    // If exponent is 0, return identity matrix. This correctly handles n=2 (exp=0).
    if (exp == 0) {
        return Matrix::identity(base.dim);
    }

    Matrix result = Matrix::identity(base.dim); // Initialize result as identity
    while (exp > 0) {
        if (exp % 2 == 1) { // If exponent is odd, multiply result by base
            result = result * base;
        }
        base = base * base; // Square the base matrix
        exp /= 2;           // Halve the exponent
    }
    return result;
}

class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        long long M = r - l + 1; // Number of distinct values available in the range [l, r]

        // Base case: If n = 1, any single value is a valid "zigzag" array.
        // There are M such values.
        if (n == 1) {
            return M;
        }

        // Base case: If only one distinct value is available (M=1) and n > 1,
        // it's impossible to form a zigzag array because adjacent elements must be different.
        if (M == 1) {
            return 0;
        }

        // For n > 1 and M > 1, we use dynamic programming with matrix exponentiation.
        // Our DP state will be (current_length, last_value_normalized, last_comparison_direction).
        // Let `dp_up[j]` be the count of zigzag arrays of `current_length`
        // ending with normalized value `j` where `arr[curr-1] < arr[curr]`.
        // Let `dp_down[j]` be the count of zigzag arrays of `current_length`
        // ending with normalized value `j` where `arr[curr-1] > arr[curr]`.

        // Normalize values to 0 to M-1 for easier indexing.
        // `j` corresponds to value `l + j`.

        // The state vector will have size 2*M:
        // [dp_up[0], ..., dp_up[M-1], dp_down[0], ..., dp_down[M-1]]
        int DIM = 2 * M;
        Matrix T(DIM); // Transition matrix

        // Build the transition matrix T
        // For dp_up_new[j] (representing state arr[i-1] < arr[i] with arr[i] = j):
        // It's formed by summing dp_down_old[p] for all p < j.
        // This means arr[i-2] > arr[i-1] where arr[i-1] = p, and then p < j.
        for (int j = 0; j < M; ++j) { // Current value 'j' (0 to M-1)
            // `T.mat[j]` represents the row for `dp_up_new[j]`
            // `T.mat[j][M + p]` means that `dp_up_new[j]` gets `dp_down_old[p]`
            for (int p = 0; p < j; ++p) { // Sum contributions from `dp_down_old[p]` where `p < j`
                T.mat[j][M + p] = 1;
            }

            // For dp_down_new[j] (representing state arr[i-1] > arr[i] with arr[i] = j):
            // It's formed by summing dp_up_old[p] for all p > j.
            // This means arr[i-2] < arr[i-1] where arr[i-1] = p, and then p > j.
            // `T.mat[M + j]` represents the row for `dp_down_new[j]`
            // `T.mat[M + j][p]` means that `dp_down_new[j]` gets `dp_up_old[p]`
            for (int p = j + 1; p < M; ++p) { // Sum contributions from `dp_up_old[p]` where `p > j`
                T.mat[M + j][p] = 1;
            }
        }

        // We need to apply the transition matrix `n-2` times
        // because our initial state vector (X_2) represents arrays of length 2,
        // and we want to reach arrays of length `n`.
        // If n=2, exp = 0, matrix_pow returns identity, correctly using X_2.
        Matrix T_final = matrix_pow(T, n - 2);

        // Initial state vector for length 2 (X_2)
        // For an array of length 2, `[v_prev, v_curr]`:
        // dp_up_2[j]: `v_curr = j`, `v_prev < j`. There are `j` choices for `v_prev` (0 to j-1).
        // dp_down_2[j]: `v_curr = j`, `v_prev > j`. There are `M - 1 - j` choices for `v_prev` (j+1 to M-1).
        std::vector<long long> initial_state_vector(DIM);
        for (int j = 0; j < M; ++j) {
            initial_state_vector[j] = j;            // `dp_up_2[j]`
            initial_state_vector[M + j] = (M - 1 - j); // `dp_down_2[j]`
        }

        // Calculate the final state vector (which represents counts for length `n`)
        // This is `T_final * initial_state_vector`
        std::vector<long long> final_state_vector(DIM, 0);
        for (int i = 0; i < DIM; ++i) { // Each row of T_final
            for (int k = 0; k < DIM; ++k) { // Each element of initial_state_vector
                final_state_vector[i] = (final_state_vector[i] + T_final.mat[i][k] * initial_state_vector[k]) % MOD;
            }
        }

        // The total number of zigzag arrays of length `n` is the sum of all elements
        // in the final state vector.
        long long total_count = 0;
        for (long long val : final_state_vector) {
            total_count = (total_count + val) % MOD;
        }

        return total_count;
    }
};