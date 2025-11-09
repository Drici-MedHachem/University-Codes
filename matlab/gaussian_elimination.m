function x = gaussian_elimination(A, b)
    % Solve A*x = b using Gaussian Elimination (no pivoting)
    % A: coefficient matrix (n x n)
    % b: right-hand side vector (n x 1)
    % x: solution vector (n x 1)

    [n, m] = size(A);
    if n ~= m
        error('Matrix A must be square');
    end

    % Form the augmented matrix
    Ab = [A, b];

    % Forward elimination
    for i = 1:n-1 % each column
        % Check for zero pivot
        if Ab(i,i) == 0
            error('Zero pivot encountered. Try pivoting!');
        end
        for j = i+1:n %each row after the row where the pivot we are picking "i"
            factor = Ab(j,i) / Ab(i,i); % the factor for each row is the element
                                        % on the same column as the pivot over the pivot
            Ab(j, :) = Ab(j, :) - factor * Ab(i, :); % R_j = R_j - factor * R_i
            % after doings this for each column all the values at the same column as the pivot are zero
        end
    end

    % Back substitution
    x = zeros(n,1);
    for i = n:-1:1 %start from the last x i.e x_n
        x(i) = (Ab(i,end) - Ab(i,i+1:n) * x(i+1:n)) / Ab(i,i); % b_i - A[i , i+1:n] dot x[i+1:n]
    end
end



