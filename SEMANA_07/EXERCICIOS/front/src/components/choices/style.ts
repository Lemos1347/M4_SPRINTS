import styled from "styled-components";

export const ButtonColor = styled.button.attrs((props) => {})`
  margin: 0 auto auto auto;
  border: none;
  border-radius: 1rem;
  background-color: ${(props) => props.background};
  color: white;
  font-size: 2rem;
  padding: 1rem;
  &:hover {
    background-color: ${(props) => props.color};
  }
`;

export const ButtonSend = styled.button.attrs((props) => {})`
  display: block;
  margin: 10rem auto 0 auto;
  border: none;
  border-radius: 1rem;
  background-color: ${(props) => props.background};
  color: white;
  font-size: 2rem;
  padding: 1rem;
  &:hover {
    background-color: ${(props) => props.color};
  }
`;