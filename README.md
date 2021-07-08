<!--
*** Thanks for checking out the Best-README-Template. If you have a suggestion
*** that would make this better, please fork the repo and create a pull request
*** or simply open an issue with the tag "enhancement".
*** Thanks again! Now go create something AMAZING! :D
-->



<!--  -->
<!--
*** I'm using markdown "reference style" links for readability.
*** Reference links are enclosed in brackets [ ] instead of parentheses ( ).
*** See the bottom of this document for the declaration of the reference variables
*** for contributors-url, forks-url, etc. This is an optional, concise syntax you may use.
*** https://www.markdownguide.org/basic-syntax/#reference-style-links
-->
<!--
[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![MIT License][license-shield]][license-url]
[![LinkedIn][linkedin-shield]][linkedin-url]
-->


<!-- PROJECT LOGO -->
<br />
<p align="center">
  </a>


  <h1 align="center">Sliding Puzzle Solver</h1>


  <p align="center">
    Optimal cpp based solver of Sliding Block Puzzle game in C++ using concepts of Graph Theory.
  </p>
</p>

![Screenshot (206)](https://user-images.githubusercontent.com/75406889/124659349-7b626600-dec2-11eb-9fcb-c09fab1ac6fa.png)

<!-- TABLE OF CONTENTS -->
<details open="open">
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
    </li>
    <li>
      <a href="#checksolvablecpp">CheckSolvable.cpp</a>
    </li>
    <li>
      <a href="#puzzlestatecpp">PuzzleState.cpp</a>
    </li> 
    <li>
      <a href="#bfscpp">BFS.cpp</a>
    </li>
    <li>
      <a href="#astarcpp">A_Star.cpp</a>
    </li>
    <li>
      <a href="#idastarcpp">IDA_Star.cpp</a>
    </li>
    <!--
    <li><a href="#acknowledgements">Acknowledgements</a></li>
    -->
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project

This is a N^N Sliding Puzzle game solver in CPP. Various graph traversal and shortest path algorithms like Breadth First Search , A Star and Iterative Deepening A Star are used to solve the N^N puzzle board.

## CheckSolvable.cpp
All instances of a sliding puzzle is not solvable. This function checks if the given instance of puzzle board is solvable or not :
1. If N is odd, then puzzle instance is solvable if number of inversions is even in the input state.
2. If N is even, puzzle instance is solvable if 
 - the blank is on an even row counting from the bottom (second-last, fourth-last, etc.) and number of inversions is odd.
 - the blank is on an odd row counting from the bottom (last, third-last, fifth-last, etc.) and number of inversions is even.
For all other cases, the puzzle instance is not solvable.

Inversion Count of a puzzle state : If we consider the board to be a single dimensional array , then inversion count is the number of tile pairs (a,b) where a<b , but index of a is more than index of b.


<!--PriceTracker.py-->
## PuzzleState.cpp
This puzzle is represented as a graph where each state of board corresponds to a different vertex and each valid movement of the blank tile (by swapping with any top , bottom , left or right tile) represents the graph edges. This file also prints the solution moves obtained from the puzzle solver. For each current state , the parent state is also present. 

Two heuristics are also maintained here : Manhattan Distance Heuristics and Hamming Distance Heuristics.

**Hamming Distance Heuristics** : Count the number of misplaced tiles between current state and goal state. It never overestimates the steps required to solve.

**Manhattan Distance Heuristics** : Sum of manhattan distances of all the numbered tiles between the current and goal state. This is a better heuritic function that reaches goal state quickly.

Also this file contains the function to backtrack and print the moves via which the puzzle state gets solved.

## BFS.cpp

This file solves the puzzle using Breadth First Search algorithm. This follows brute force approach to reach the target state. Maintains a visited list of states to avoid visiting the same state again. Since it is a shortest path based algo , the solution state nearest to the root is always found. But it is not so efficient in terms of memory and time usage and ends up taking the same number of moves as Depth First Search.

## A_Star.cpp

Here, the puzzle is solved using A_star algorithm , which turns out to be the fastest solver. Here each move is always made to the state with least cost. This approximate cost F(x) is calculated as : **F(x) = g(x) + h(x)** where , g(x) gives the number of misplaced tiles between current and solved state , while h(x) is a heuristics function. 
Two types of heuristics are used here , Hamming distance and Manhattan Distance Heuristics , which intelligently underestimates the moves required to reach goal state. In this way it avoids searching sub trees that do not contain an answer , and only explore sub trees with the least cost.

## IDA_Star.cpp

This file solves the puzzle using Iterative Deepening A Star algorithm , which is a variant of Iterative Deepening Depth First Search and A Star. This puzzle solver is the memory efficient variant of the above algorithms , because it does not maintain a list of visited states , and may end up visiting the same states again. Because heuristics is used to calculate approximate cost of each state , it doesn't search for goal state in subtrees that do not contain a solution state. Also in the worst case the nodes with smaller depth (i.e. the nodes without more branching & depth) are visisted more than once.

<!-- CONTRIBUTING 
## Contributing

Contributions are what make the open source community such an amazing place to be learn, inspire, and create. Any contributions you make are **greatly appreciated**.

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

-->

<!-- LICENSE 
## License

Distributed under the MIT License. See `LICENSE` for more information.

-->

<!-- CONTACT 
## Contact

Your Name - [@your_twitter](https://twitter.com/your_username) - email@example.com

Project Link: [https://github.com/your_username/repo_name](https://github.com/your_username/repo_name)
-->


<!-- ACKNOWLEDGEMENTS 
## Acknowledgements
* [GitHub Emoji Cheat Sheet](https://www.webpagefx.com/tools/emoji-cheat-sheet)
* [Img Shields](https://shields.io)
* [Choose an Open Source License](https://choosealicense.com)
* [GitHub Pages](https://pages.github.com)
* [Animate.css](https://daneden.github.io/animate.css)
* [Loaders.css](https://connoratherton.com/loaders)
* [Slick Carousel](https://kenwheeler.github.io/slick)
* [Smooth Scroll](https://github.com/cferdinandi/smooth-scroll)
* [Sticky Kit](http://leafo.net/sticky-kit)
* [JVectorMap](http://jvectormap.com)
* [Font Awesome](https://fontawesome.com)

-->



<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/github/contributors/othneildrew/Best-README-Template.svg?style=for-the-badge
[contributors-url]: https://github.com/othneildrew/Best-README-Template/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/othneildrew/Best-README-Template.svg?style=for-the-badge
[forks-url]: https://github.com/othneildrew/Best-README-Template/network/members
[stars-shield]: https://img.shields.io/github/stars/othneildrew/Best-README-Template.svg?style=for-the-badge
[stars-url]: https://github.com/othneildrew/Best-README-Template/stargazers
[issues-shield]: https://img.shields.io/github/issues/othneildrew/Best-README-Template.svg?style=for-the-badge
[issues-url]: https://github.com/othneildrew/Best-README-Template/issues
[license-shield]: https://img.shields.io/github/license/othneildrew/Best-README-Template.svg?style=for-the-badge
[license-url]: https://github.com/othneildrew/Best-README-Template/blob/master/LICENSE.txt
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://linkedin.com/in/othneildrew
[product-screenshot]: images/screenshot.png
