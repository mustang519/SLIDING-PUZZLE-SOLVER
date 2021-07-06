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

<!--PriceTracker.py-->
## PuzzleState.cpp
This puzzle is represented as a graph where each board corresponds to a different vertex and the movement of the blank tile (by swapping with any top , bottom , left or right tile) represents the graph edges. This file also prints the solution moves obtained from the puzzle solver. 

Two heuristics are also maintained here : Manhattan Distance Heuristics and Hamming Distance Heuristics.

**Hamming Distance Heuristics** : Count the number of misplaced tiles between current state and goal state. It never overestimates the steps required to solve.

**Manhattan Distance Heuristics** : Sum of manhattan distances of all the numbered tiles between the current and goal state. This is a better heuritic function that reaches goal state quickly.

## CheckSolvable.cpp

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
