import React from "react";

export interface IChoices {
  disabled: boolean;
  response: number[];
  trueSequence: number[];
  setResponse: React.Dispatch<React.SetStateAction<number[]>>;
  setEndGame: React.Dispatch<React.SetStateAction<boolean>>;
  setTrueSequence: React.Dispatch<React.SetStateAction<number[]>>;
  setWatching: React.Dispatch<React.SetStateAction<boolean>>;
}

export interface IPlayingContext {
  playing: boolean;
  setPlaying: React.Dispatch<React.SetStateAction<boolean>>;
}

export interface IPlayerContext {
  playerOne: boolean;
  playerTwo: boolean;
  setPlayerOne: React.Dispatch<React.SetStateAction<boolean>>;
  setPlayerTwo: React.Dispatch<React.SetStateAction<boolean>>;
}

export interface ISequence {
  sequence: number[];
}
