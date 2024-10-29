<h1> <img src="https://user-images.githubusercontent.com/72338271/119033660-c32e3c00-b9ad-11eb-9f05-c28a6e213e4b.gif" width="25"> Darwin Project </h1>

Simple console app developed on first year of my undergraduate computer science study at Silesian University Of Technology.
<p> Darwin is a program using genetical algorithm. The process of this program can be listed as below: <br>
<ul> 
  <li> User provides the program with data, like: 
    <ul>
     <li> Number of k-pairs chosen to reproduce </li>
     <li> Number of p-generations </li>
     <li> Extinction factor that belongs to the interval <0,1> </li>
     <li> Reproduction factor that belongs to the interval <0,1> </li>
     <li> Name of the input file</li>
     <li> Name of the output file</li>
    </ul>
  </li>
  <li> Every inputted parameter is being checked whether it is in correct format or not. If something is wrong a simple instruction pops up. </li>
  <li> Program saves the data from the file in order to operate on it </li>
    <ul>
      <li> The data is stored in this format: <br> <img src="https://user-images.githubusercontent.com/72338271/119059676-1665b600-b9d1-11eb-9021-e213859cab2b.png"> <br> Every sequence of numbers is just a genetic code of a specific individual. 
      </li>
    </ul>
  <li> 2 individuals are chosen from the population and the outcome of their reproduction are two another individuals. <br> More or less it means that the process of crossing-   over is happening. 
  <ul>
    <li> It can be depicted as below: <br> <img src ="https://user-images.githubusercontent.com/72338271/119060582-c2f46780-b9d2-11eb-9c4d-c0341766a3cb.png"> </li>
    <li> This process is repeated k-times </li> 
  </ul>
  </li>
  <li> Every individual is getting assigned a factor of survival. It is calculated using the value of it's genetic code elements. </li>
  <ul>
      <li>This factor determines whether an individual will be extinct, or will it continue to reproduce in further generations, or will it just exist. </li>
  </ul>
  <li> Previous steps (excluding those before reading data from files) are repeated p-times </li>
  <li> Whole population is being saved on a text file that is the final outcome of this program </li>
</ul>

For more info about the program, see ProjectReportAndDocs.pdf - there is an instruction in polish at the beginning ;)