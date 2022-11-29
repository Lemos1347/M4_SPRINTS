import { useContext } from "react";
import { PlayerContext } from "../../context/player";
import { IChoices } from "../../interfaces";
import api from "../../utils/axios";
import { ButtonColor, ButtonSend } from "./style";

export const Choices = ({
  disabled,
  trueSequence,
  response,
  setResponse,
  setEndGame,
  setTrueSequence,
  setWatching,
}: IChoices) => {
  const { playerOne, playerTwo, setPlayerOne, setPlayerTwo } =
    useContext(PlayerContext);

  const handleColorButton = (color: string) => {
    switch (color) {
      case "green":
        setResponse((prev) => {
          return [...prev, 1];
        });
        break;
      case "red":
        setResponse((prev) => {
          return [...prev, 2];
        });
        break;
      case "yellow":
        setResponse((prev) => {
          return [...prev, 3];
        });
        break;
      case "blue":
        setResponse((prev) => {
          return [...prev, 4];
        });
        break;
    }
  };

  const handleSendButton = async () => {
    for (let i = 0; i < trueSequence.length; i++) {
      if (trueSequence[i] !== response[i]) {
        throw new Error("Sequencia Errada");
      }
      console.log("Passou");
    }
  };

  const sendNewSequence = () => {
    const newNumber: number = Math.floor(Math.random() * 4) + 1;
    setWatching(true);
    setTrueSequence((prev) => {
      return [...prev, newNumber];
    });
    if (playerOne) {
      setPlayerOne(false);
      setPlayerTwo(true);
    } else if (playerTwo) {
      setPlayerOne(true);
      setPlayerTwo(false);
    }
  };

  return (
    <>
      <div
        style={{
          display: "flex",
        }}
      >
        {!disabled ? (
          <>
            <ButtonColor
              color="green"
              background="black"
              onClick={() => {
                handleColorButton("green");
              }}
            >
              Verde
            </ButtonColor>
            <ButtonColor
              color="red"
              background="black"
              onClick={() => {
                handleColorButton("red");
              }}
            >
              Vermelho
            </ButtonColor>
            <ButtonColor
              color="yellow"
              background="black"
              onClick={() => {
                handleColorButton("yellow");
              }}
            >
              Amarelo
            </ButtonColor>
            <ButtonColor
              color="blue"
              background="black"
              onClick={() => {
                handleColorButton("blue");
              }}
            >
              Azul
            </ButtonColor>
          </>
        ) : (
          <>
            <ButtonColor disabled background="gray">
              Verde
            </ButtonColor>
            <ButtonColor disabled background="gray">
              Vermelho
            </ButtonColor>
            <ButtonColor disabled background="gray">
              Amarelo
            </ButtonColor>
            <ButtonColor disabled background="gray">
              Azul
            </ButtonColor>
          </>
        )}
      </div>
      {!disabled ? (
        <ButtonSend
          background="black"
          color="blue"
          onClick={() => {
            handleSendButton()
              .then(() => {
                sendNewSequence();
                playerOne ? setPlayerTwo(true) : setPlayerOne(true);
              })
              .catch((err) => {
                console.log(err);
                api.get("/");
                setEndGame(true);
              });
          }}
        >
          ENVIAR
        </ButtonSend>
      ) : (
        <ButtonSend background="gray" disabled>
          ENVIAR
        </ButtonSend>
      )}
    </>
  );
};
