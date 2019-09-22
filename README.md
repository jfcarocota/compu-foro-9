# Fundamentos de computación, foro 9
 
 ## Quicksort
 
<p  align="justify">
Quicksort, como merge sort, aplica el paradigma de divide y vencerás introducido en la Sección 2.3.1. Aquí está el proceso de dividir y conquistar de tres pasos para clasificar un subarreglo típico A[p..r].
<p>

## Divide

<p  align="justify">
Particiona (reorganiza) la matriz A[p..r] en dos subconjuntos (posiblemente vacíos) A[p..q - 1]  y A[q + 1..r] de modo que cada elemento de A[p..q - 1] sea menor o igual que A[q + 1..r], que es, a su vez, menor o igual que cada elemento de A[q + 1..r]. Calcule el índice q como parte de este procedimiento de partición.
<p>
 
## Vence
  
<p  align="justify">
Ordena las dos submatrices A[p..q - 1] y A[q + 1..r] por llamadas recursivas ordenar rápidamente. 
<p>

## Combinar

<p  align="justify">
Como las submatrices ya están ordenadas, no es necesario trabajar para combinarlas, toda la matriz A[p..r] ahora está ordenada.
El tiempo de ejecución de quicksort depende de si la partición es equilibrada o desequilibrado, que a su vez depende de qué elementos se utilizan para la partición. Si la partición está equilibrada, el algoritmo se ejecutará asintóticamente tan rápido como el el ordenamiento de mezcla. Sin embargo, si la partición no está equilibrada, puede ejecutarse asintóticamente tan lentamente como tipo de inserción. 
Según de esta explicación uno de los peores casos es que todos los componentes del conjunto sean iguales, en donde se provoca un conjunto de redundancias donde el algoritmo trata de ordenar de un lado a a un lado b de sus extremos, haciendo que tome más tiempo con menos contenido. Para esto nos basaremos en algoritmo Dutch National Flag.
Este problema también se puede ver en términos de reorganizar elementos de una matriz. Suponga que cada uno de los elementos posibles podría clasificarse exactamente en una de las tres categorías (inferior, central y superior). Por ejemplo, si todos los elementos están en 0 ... 1, la parte inferior se podría definir como elementos en 0 ... 0.1 (sin incluir 0.1), el medio como 0.1 ... 0.3 (sin incluir 0.3) y la parte superior como 0.3 y mayor. (La elección de estos valores ilustra que las categorías no necesitan ser rangos iguales). El problema es, entonces, producir una matriz tal que todos los elementos "inferiores" estén antes (tengan un índice menor que el índice de) todos los elementos "intermedios", que vienen antes que todos los elementos "superiores".
<p>
 
 ![image](https://user-images.githubusercontent.com/6539267/65395079-e1601680-dd4a-11e9-89af-8418e5a88d4c.png)

 ![image](https://user-images.githubusercontent.com/6539267/65395088-f63caa00-dd4a-11e9-8200-a7773b663ebc.png)

![image](https://user-images.githubusercontent.com/6539267/65395091-ff2d7b80-dd4a-11e9-9553-13d192d59348.png)


```c++
//Dutch National Flag Algorithm 
const void Quicksort::Partition(int a[], int low, int high, int &i, int &j) 
{ 
    if (high - low <= 1) 
    { 
        if (a[high] < a[low]) 
            std::swap(a[high], a[low]); 
        i = low; 
        j = high; 
        return; 
    } 
  
    int mid = low; 
    int pivot = a[high]; 
    while (mid <= high) 
    { 
        if (a[mid]<pivot) 
            std::swap(a[low++], a[mid++]); 
        else if (a[mid]==pivot) 
            mid++; 
        else if (a[mid]>pivot) 
            std::swap(a[mid], a[high--]); 
    } 
  
    //update i and j 
    i = low-1; 
    j = mid; //or high-1 
} 
  
const void Quicksort::Sorting(int a[], int low, int high) 
{ 
    if (low>=high) 
        return; 
  
    int i, j; 
  
    Quicksort::Partition(a, low, high, i, j); 
  
    Quicksort::Sorting(a, low, i); 
    Quicksort::Sorting(a, j, high); 
} 
```
