#pragma omp parallel for private(divisor,is_prime) schedule(dynamic,20) ordered

#pragma omp ordered