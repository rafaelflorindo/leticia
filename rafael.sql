-- phpMyAdmin SQL Dump
-- version 4.8.0.1
-- https://www.phpmyadmin.net/
--
-- Host: localhost
-- Tempo de geração: 13/05/2019 às 16:54
-- Versão do servidor: 10.1.32-MariaDB
-- Versão do PHP: 7.2.5

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Banco de dados: `rafael`
--
CREATE DATABASE IF NOT EXISTS `rafael` DEFAULT CHARACTER SET latin1 COLLATE latin1_swedish_ci;
USE `rafael`;

-- --------------------------------------------------------

--
-- Estrutura para tabela `aluno`
--

CREATE TABLE `aluno` (
  `id` int(11) NOT NULL,
  `nome` varchar(100) NOT NULL,
  `git` varchar(100) DEFAULT NULL,
  `url` varchar(100) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Fazendo dump de dados para tabela `aluno`
--

INSERT INTO `aluno` (`id`, `nome`, `git`, `url`) VALUES
(1, 'Gabriel Leon', 'https://github.com/GabrielLeonBS/Provas', ''),
(3, 'Robert', 'https://github.com/RobertAgnelo/PROVA', ''),
(4, 'Carlos Eduardo', '', ''),
(9, 'Gabriel Murilo', NULL, NULL),
(10, 'Juan', NULL, NULL);

-- --------------------------------------------------------

--
-- Estrutura para tabela `alunoAtividade`
--

CREATE TABLE `alunoAtividade` (
  `id` int(11) NOT NULL,
  `idAluno` int(11) NOT NULL,
  `idAtividade` int(11) NOT NULL,
  `nota` decimal(10,0) NOT NULL,
  `anotacoes` longtext NOT NULL,
  `dataPostagem` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Fazendo dump de dados para tabela `alunoAtividade`
--

INSERT INTO `alunoAtividade` (`id`, `idAluno`, `idAtividade`, `nota`, `anotacoes`, `dataPostagem`) VALUES
(1, 1, 1, '3', 'Faltou colocar o tamanho dos campos e problemas com relacionamentos de produtos vendidos', '2019-05-13'),
(2, 3, 1, '3', 'Faltou imprimir os dados em php', '2019-05-13'),
(3, 3, 2, '3', 'Faltou colocar o tamanho dos campos e problemas com relacionamentos de produtos vendidos', '2019-05-13'),
(4, 4, 2, '0', 'Faltou link git', '0000-00-00'),
(5, 4, 1, '2', 'Problemas com relacionamentos\r\nNão listou os relacionamentos\r\nFaltou o link do github', '2019-05-13'),
(6, 9, 1, '2', 'Problemas com relacionamentos\r\nNão listou os relacionamentos\r\nFaltou o link do gitHub', '2019-05-13');

-- --------------------------------------------------------

--
-- Estrutura para tabela `atividade`
--

CREATE TABLE `atividade` (
  `id` int(11) NOT NULL,
  `atividade` varchar(100) NOT NULL,
  `descricao` longtext NOT NULL,
  `url` varchar(100) NOT NULL,
  `dataInicio` date NOT NULL,
  `dataFim` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Fazendo dump de dados para tabela `atividade`
--

INSERT INTO `atividade` (`id`, `atividade`, `descricao`, `url`, `dataInicio`, `dataFim`) VALUES
(1, 'Banco de Dados - 3.info', '', '', '2019-05-06', '2019-05-13'),
(2, 'IPW - 3.info', '', '', '2019-05-06', '2019-05-13');

--
-- Índices de tabelas apagadas
--

--
-- Índices de tabela `aluno`
--
ALTER TABLE `aluno`
  ADD PRIMARY KEY (`id`),
  ADD UNIQUE KEY `git` (`git`);

--
-- Índices de tabela `alunoAtividade`
--
ALTER TABLE `alunoAtividade`
  ADD PRIMARY KEY (`id`),
  ADD KEY `fkidAluno` (`idAluno`),
  ADD KEY `fkidAtividade` (`idAtividade`);

--
-- Índices de tabela `atividade`
--
ALTER TABLE `atividade`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT de tabelas apagadas
--

--
-- AUTO_INCREMENT de tabela `aluno`
--
ALTER TABLE `aluno`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;

--
-- AUTO_INCREMENT de tabela `alunoAtividade`
--
ALTER TABLE `alunoAtividade`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=7;

--
-- AUTO_INCREMENT de tabela `atividade`
--
ALTER TABLE `atividade`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- Restrições para dumps de tabelas
--

--
-- Restrições para tabelas `alunoAtividade`
--
ALTER TABLE `alunoAtividade`
  ADD CONSTRAINT `fkidAluno` FOREIGN KEY (`idAluno`) REFERENCES `aluno` (`id`),
  ADD CONSTRAINT `fkidAtividade` FOREIGN KEY (`idAtividade`) REFERENCES `atividade` (`id`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
