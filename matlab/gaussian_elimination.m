
  % Solve A*x = b using Gaussian Elimination (no pivoting)
  % A: coefficient matrix (n x n)
  % b: right-hand side vector (n x 1)
  % x: solution vector (n x 1)
  clc;clear
  %A = [2 1 4 -2; -3 4 2 -1; 3 5 -2 1; -2 3 2 4];
  %b = [19; 1; 8 ; 13];
  A = [1,1;3,-2];
  b = [3;4];
  [n, m] = size(A);
  if n ~= m
      error('Matrix A must be square');
  end

  % Form the augmented matrix
  Ab = [A, b];

  % Forward elimination
  for j = 1:n-1 % each column

      % Check for zero pivot
      if Ab(j,j) == 0
        pivot_found = false;
        %looking for the row to swap
          for i=j+1:n
            if Ab(i,j) ~= 0
              temp = Ab(i,:);
              Ab(i,:) = Ab(j,:);
              A(j,:) = temp;
              pivot_found = true;
              break;
            endif
          endfor
          % if we didn't find a proper row to swap while still 0
          if ~pivot_found
            continue;
          endif
      endif


      for i = j+1:n %each row after the row where the pivot we are picking "i"
          factor = Ab(i,j) / Ab(j,j); % the factor for each row is the element
                                      % on the same column as the pivot over the pivot
          Ab(i, :) = Ab(i, :) - factor * Ab(j, :); % R_i = R_i - factor * R_j
          % after doings this for each column all the values at the same column as the pivot are zero
      endfor


  endfor

  % Back substitution
  x = zeros(n,1);
  for i = n:-1:1 %start from the last x i.e x_n
      x(i) = (Ab(i,end) - Ab(i,i+1:n) * x(i+1:n)) / Ab(i,i); % b_i - A[i , i+1:n] dot x[i+1:n]
  endfor
  disp(x)




