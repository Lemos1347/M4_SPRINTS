import { ButtonColor } from "./style";
import api from "../../utils/axios";
import { Title } from "../title";
import { useContext, useEffect, useState } from "react";
import { PlayingContext } from "../../context/playing";
import { Choices } from "../choices";
import { PlayerContext } from "../../context/player";

const PlayingPage = () => {
  let temp: string;
  const { playing, setPlaying } = useContext(PlayingContext);
  const { playerOne, playerTwo, setPlayerOne, setPlayerTwo } =
    useContext(PlayerContext);

  const [watching, setWatching] = useState<boolean>(true);
  const [endGame, setEndGame] = useState<boolean>(false);
  const [response, setResponse] = useState<number[]>([]);
  const [trueSequence, setTrueSequence] = useState<number[]>([1]);

  useEffect(() => {
    for (let i = 0; i < trueSequence.length; i++) {
      let str = trueSequence[i].toString();
      temp += str;
    }
    api
      .post("/post", { body: temp })
      .then(() => {
        setTimeout(() => {
          setWatching(false);
          setResponse([]);
        }, trueSequence.length * 1000);
      })
      .catch((err) => {
        console.log(err);
      });
  }, [trueSequence]);

  useEffect(() => {
    console.log("PlayerOne: ", playerOne);
    console.log("PlayerTwo: ", playerTwo);
  }, [playerOne]);

  return (
    <>
      {!endGame ? (
        <>
          <Title value="JOGANDO..." />
          <Title value={playerOne ? "Jogador 1" : "Jogador 2"} />
          <Choices
            disabled={watching}
            response={response}
            trueSequence={trueSequence}
            setResponse={setResponse}
            setEndGame={setEndGame}
            setTrueSequence={setTrueSequence}
            setWatching={setWatching}
          />
        </>
      ) : (
        <>
          <Title value="GANHADOR:" />
          <Title value={playerOne ? "JOGADOR DOIS!" : "JOGADOR UM!"} />
          <div
            style={{
              display: "flex",
            }}
          >
            <ButtonColor
              color="blue"
              background="black"
              onClick={() => {
                setPlaying(false);
              }}
            >
              VOLTAR
            </ButtonColor>
          </div>
        </>
      )}
    </>
  );
};
export default PlayingPage;
