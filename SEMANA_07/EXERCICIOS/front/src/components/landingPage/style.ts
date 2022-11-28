import styled from "styled-components";

export const LandingPageContainer = styled.div`
  margin: 5% 0 0 0;
  justify-content: center;
  width: 100%;
  height: 100%;
  text-align: center;
`;

export const Title = styled.h1`
  margin: 0 0 10% 0;
  font-size: 3rem;
  text-align: center;
  justify-content: center;
`;

export const Button = styled.button`
  display: block;
  margin: 1rem auto 0 auto;
  border: none;
  border-radius: 1rem;
  background-color: black;
  color: white;
  font-size: 2rem;
  padding: 1rem;
  &:hover {
    background-color: blue;
  }
`;

export const ContainerInformation = styled.div`
  width: 50%;
  height: 100%;
  text-align: center;
  font-size: 2rem;
  margin: 1rem auto auto auto;
  justify-content: center;
  position: relative;
`;
