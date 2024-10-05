-- phpMyAdmin SQL Dump
-- version 5.1.1deb5ubuntu1
-- https://www.phpmyadmin.net/
--
-- Hôte : localhost:3306
-- Généré le : sam. 05 oct. 2024 à 17:06
-- Version du serveur : 8.0.39-0ubuntu0.22.04.1
-- Version de PHP : 8.1.2-1ubuntu2.19

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données : `Banque`
--

-- --------------------------------------------------------

--
-- Structure de la table `Clients`
--

CREATE TABLE `Clients` (
  `ID` int NOT NULL,
  `Nom` varchar(255) NOT NULL,
  `Prenom` varchar(255) NOT NULL,
  `Telephone` varchar(255) NOT NULL,
  `CIN` varchar(255) NOT NULL,
  `Code_Secu` int NOT NULL,
  `RIB` varchar(255) NOT NULL,
  `Type_Compte` int NOT NULL,
  `Solde` double NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;

--
-- Déchargement des données de la table `Clients`
--

INSERT INTO `Clients` (`ID`, `Nom`, `Prenom`, `Telephone`, `CIN`, `Code_Secu`, `RIB`, `Type_Compte`, `Solde`) VALUES
(1, 'Guillaume', 'Corentin', '0787316820', 'FR-AAAC9171G211', 2909, 'FR1234567891', 1, 500),
(2, 'Sungur', 'Etem', '0678485214', 'FR-AAAC9171G212', 1458, 'FR1234567892', 1, 15500),
(3, 'Pereira', 'Luka', '0745854125', 'FR-AAAC9171G213', 1402, 'FR1234567893', 1, 2000);

--
-- Index pour les tables déchargées
--

--
-- Index pour la table `Clients`
--
ALTER TABLE `Clients`
  ADD PRIMARY KEY (`ID`);

--
-- AUTO_INCREMENT pour les tables déchargées
--

--
-- AUTO_INCREMENT pour la table `Clients`
--
ALTER TABLE `Clients`
  MODIFY `ID` int NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
